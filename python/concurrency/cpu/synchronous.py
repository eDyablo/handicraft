#!/usr/bin/env python3

import time


def find_sum(number):
    return sum(i * i for i in range(number))


def find_sums(numbers):
    for number in numbers:
        find_sum(number)


def main():
    numbers = [5_000_000 + x for x in range(20)]
    start_time = time.time()
    find_sums(numbers)
    end_time = time.time()
    duration = end_time - start_time
    print(f"Duration {duration} seconds")


if __name__ == "__main__":
    main()
