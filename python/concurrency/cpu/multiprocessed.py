#!/usr/bin/env python3

import multiprocessing
import time


def find_sum(number):
    return sum(i * i for i in range(number))


def find_sums(numbers):
    with multiprocessing.Pool() as pool:
        return pool.map(find_sum, numbers)


def main():
    numbers = [5_000_000 + x for x in range(20)]
    start_time = time.time()
    result = find_sums(numbers)
    end_time = time.time()
    duration = end_time - start_time
    print(f"Result {result}")
    print(f"Duration {duration} seconds")


if __name__ == "__main__":
    main()
