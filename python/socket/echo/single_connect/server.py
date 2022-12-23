#!/usr/bin/env python3

from argparse import ArgumentParser
import socket


def main(args):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.bind((args.address, args.port))
        server.listen()
        client, client_address = server.accept()
        with client:
            print(f"connected by {client_address}")
            while (data := client.recv(1024)):
                print(f"received {data!r}")
                client.sendall(data)


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
