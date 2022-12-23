#!/usr/bin/env python3

from argparse import ArgumentParser
from types import SimpleNamespace
import selectors
import socket


selector = selectors.DefaultSelector()


def read(socket, data):
    received = socket.recv(1024)
    if received:
        print(f"redeived {received!r}")
    else:
        print("closing connection")
        selector.unregister(socket)
        socket.close()


def write(socket, data):
    if data.output:
        print(f"sending {data.output!r}")
        sent_count = socket.send(data.output)
        data.output = data.output[sent_count:]


def main(args):
    print(f"starting connection to {args.host}:{args.port}")
    with selector, socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.setblocking(False)
        client_socket.connect_ex((args.host, args.port))
        client_data = SimpleNamespace(output=(args.data or input()).encode())
        selector.register(client_socket, selectors.EVENT_READ |
                          selectors.EVENT_WRITE, data=client_data)
        while True:
            for key, mask in selector.select():
                if mask & selectors.EVENT_READ:
                    read(key.fileobj, key.data)
                if mask & selectors.EVENT_WRITE:
                    write(key.fileobj, key.data)


def parse_args():
    port_range = range(1, 65536)
    parser = ArgumentParser(description="echo client")
    parser.add_argument("-s", "--host", type=str, default="localhost")
    parser.add_argument("-p",
                        "--port",
                        type=int,
                        choices=port_range,
                        default=1024, metavar=f"PORT{{{port_range.start}..{port_range.stop-1}}}")
    parser.add_argument("-d", "--data", type=str)
    return parser.parse_args()


if __name__ == "__main__":
    main(parse_args())
