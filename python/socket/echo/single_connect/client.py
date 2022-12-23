#!/usr/bin/env python3

from argparse import ArgumentParser
import socket


def main(args):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.connect((args.host, args.port))
        server.sendall((args.data or input()).encode())
        response = server.recv(1024)
        print(f"received {response!r}")


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
