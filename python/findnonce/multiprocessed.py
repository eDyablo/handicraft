#!/usr/bin/env python3

from argparse import ArgumentParser
from binascii import hexlify, unhexlify
from itertools import chain, repeat
import multiprocessing
import hashlib


def get_hash(data, nonce):
    return hashlib.sha256(bytes(chain(nonce.to_bytes(4, byteorder="big"), data)))


def is_resolved(a_hash, pattern):
    return len(pattern) == 0 or a_hash.digest()[0: len(pattern)] == pattern


def worker(nonce_range, data, pattern, resolved_event):
    for count, nonce in enumerate(nonce_range):
        if resolved_event.is_set():
            return (nonce, bytes(), count)
        elif is_resolved(hash := get_hash(data, nonce), pattern):
            resolved_event.set()
            return (nonce, hash.digest(), count)


def main(args):
    data = input().encode()
    worker_count = multiprocessing.cpu_count()
    nonce_min = 0
    nonce_max = 0xFFFFFFFF + 1  # 4,294,967,296I
    nonce_delta = -(
        (nonce_max - nonce_min + 1) // -worker_count
    )  # do ceiling instead of flooring
    nonce_ranges = (
        range(i * nonce_delta, min(nonce_max, (i + 1) * nonce_delta))
        for i in range(worker_count)
    )
    with multiprocessing.Manager() as manager:
        resolved = manager.Event()
        with multiprocessing.Pool() as pool:
            results = pool.starmap(worker, zip(
                nonce_ranges, repeat(data), repeat(unhexlify(args.prefix)), repeat(resolved)))
    if winner := next(filter(lambda result: result[1], results), None):
        print(winner[0], hexlify(winner[1]).decode())


def parse_args():
    parser = ArgumentParser()
    parser.add_argument("-p", "--prefix", type=str,
                        metavar="HEXADECIMALS", default=bytes())
    return parser.parse_args()


if __name__ == "__main__":
    main(parse_args())
