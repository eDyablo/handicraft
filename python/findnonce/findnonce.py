#!/usr/bin/env python3

from argparse import ArgumentParser
from binascii import hexlify, unhexlify
from itertools import chain
from threading import Thread
import hashlib
import os

pattern = bytes()
resolved = False


class CompletedWorker:
    def __init__(self, a_hash, nonce):
        self._hash = a_hash
        self._nonce = nonce

    @property
    def digest(self):
        return self._hash.digest() if self._hash else bytes()

    @property
    def nonce(self):
        return self._nonce


def get_hash(data, nonce):
    return hashlib.sha256(bytes(chain(nonce.to_bytes(4, byteorder="big"), data)))


def is_resolved(a_hash):
    global pattern
    return len(pattern) == 0 or a_hash.digest()[0: len(pattern)] == pattern


class RunningWorker(Thread):
    def __init__(self, data, nonce_range):
        super().__init__()
        self._data = data
        self._nonce_range = nonce_range
        self._hash = None
        self._nonce = 0

    def run(self):
        global resolved
        for nonce in self._nonce_range:
            if resolved:
                break
            if is_resolved(a_hash := get_hash(self._data, nonce)):
                resolved = True
                self._hash = a_hash
                self._nonce = nonce
                break

    def join(self, timeout=0) -> CompletedWorker:
        super().join()
        return CompletedWorker(self._hash, self._nonce)


class Worker:
    def __init__(self, data, nonce_range):
        self._data = data
        self._nonce_range = nonce_range

    def start(self) -> RunningWorker:
        worker = RunningWorker(self._data, self._nonce_range)
        worker.start()
        return worker


def parse_args():
    parser = ArgumentParser()
    parser.add_argument("-p", "--prefix", type=str, metavar="HEXADECIMALS", default=bytes())
    return parser.parse_args()


def main(args):
    global pattern
    pattern = unhexlify(args.prefix)
    data = input().encode()
    worker_count = os.cpu_count()
    nonce_min = 0
    nonce_max = 0xFFFFFFFF + 1  # 4,294,967,296I
    nonce_delta = -(
            (nonce_max - nonce_min + 1) // -worker_count
    )  # do ceiling instead of flooring
    nonce_ranges = (
        range(i * nonce_delta, min(nonce_max, (i + 1) * nonce_delta))
        for i in range(worker_count)
    )
    workers = (Worker(data, nonce_range) for nonce_range in nonce_ranges)
    workers = list(worker.start() for worker in workers)
    workers = (worker.join() for worker in workers)
    if winner := next(filter(lambda worker: worker.digest, workers), None):
        print(winner.nonce, hexlify(winner.digest).decode())


if __name__ == "__main__":
    main(parse_args())
