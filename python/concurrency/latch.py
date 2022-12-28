#!/usr/bin/env python3
"""
https://superfastpython.com/thread-countdown-latch/#Example_of_Using_a_Countdown_Latch
"""

from random import random, sample
from time import sleep
from threading import Condition, Thread, current_thread


class Latch:

  def __init__(self, parties):
    self._parties = parties
    self._condition = Condition()

  @property
  def parties(self):
    return self._parties

  def pass_through(self):
    with self._condition:
      if self._parties == 0:
        return
      else:
        self._parties -= 1
        if self._parties == 0:
          self._condition.notify_all()

  def wait(self, timeout=None):
    with self._condition:
      if self._parties == 0:
        return
      else:
        self._condition.wait(timeout)


def log(message):
  print(f"{current_thread().name:>16} {message}")


def work(latch):
  log("started")
  sleep(random() * 2)
  latch.pass_through()
  log("done")


def main():
  latch = Latch(5)
  workers = [Thread(target=work, args=(latch, )) for _ in range(latch.parties)]
  [worker.start() for worker in sample(workers, len(workers))]
  log("waiting on latch...")
  latch.wait()
  log("done")


if __name__ == "__main__":
  main()
