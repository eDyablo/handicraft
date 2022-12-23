#!/usr/bin/env python3

from argparse import ArgumentParser
from types import SimpleNamespace
import selectors
import socket

selector = selectors.DefaultSelector()


def accept(socket):
    client_socket, address = socket.accept()
    print(f"accepted connection from {address!r}")
    client_socket.setblocking(False)
    selector.register(client_socket, selectors.EVENT_READ | selectors.EVENT_WRITE,
                      data=SimpleNamespace(address=address, input=bytes(), output=bytes()))


def read(socket, data):
    if (received := socket.recv(1024)):
        print(f"received {received!r}")
        data.output += received
    else:
        print(f"closing connection to {data.address!r}")
        selector.unregister(socket)
        socket.close()


def write(socket, data):
    if data.output:
        print(f"echoing {data.output!r} to {data.address!r}")
        sent_count = socket.send(data.output)
        data.output = data.output[sent_count:]


def main(args):
    with selector, socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((args.address, args.port))
        server_socket.listen()
        print(f"listening on {args.address}:{args.port}")
        server_socket.setblocking(False)
        selector.register(server_socket, selectors.EVENT_READ, data=None)
        while True:
            for key, mask in selector.select():
                if not key.data:
                    accept(key.fileobj)
                elif mask & selectors.EVENT_READ:
                    read(key.fileobj, key.data)
                elif mask & selectors.EVENT_WRITE:
                    write(key.fileobj, key.data)


def parse_args():
    port_range = range(1, 65536)
    parser = ArgumentParser(description="echo server")
    parser.add_argument("-a", "--address", type=str, default="localhost")
    parser.add_argument("-p",
                        "--port",
                        type=int,
                        choices=port_range,
                        default=1024, metavar=f"PORT{{{port_range.start}..{port_range.stop-1}}}")
    return parser.parse_args()


if __name__ == "__main__":
    main(parse_args())
