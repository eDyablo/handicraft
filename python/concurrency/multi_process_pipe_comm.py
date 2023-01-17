#!/usr/bin/env python3

from multiprocessing import current_process
from multiprocessing import Pipe
from multiprocessing import Process
from random import random
from threading import current_thread
from time import sleep
from types import SimpleNamespace


def log(message):
    print(f"{current_process().name:>16}:{current_thread().name:<16} {message}")


def produce(connection):
    log("started")
    for id in range(5):
        item = SimpleNamespace(id=id)
        sleep(random())
        log(f"send {item}")
        connection.send(item)
    connection.send(None)
    log("done")


def consume(connection):
    log("started")
    while (item := connection.recv()) is not None:
        log(f"received {item}")
    log("done")


def main():
    log("started")
    pipe = Pipe()
    processes = [
        Process(target=produce, args=(pipe[0], )),
        Process(target=consume, args=(pipe[1], )),
    ]
    [process.start() for process in processes]
    [process.join() for process in processes]
    log("done")


if __name__ == "__main__":
    main()
