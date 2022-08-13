#!/usr/bin/env python3

import asyncio
import time


async def find_sum(number):
    sum = 0
    for i in range(number):
        sum += i * i
        await asyncio.sleep(0)
    return sum


async def find_sums(numbers):
    tasks = (asyncio.ensure_future(find_sum(number)) for number in numbers)
    return await asyncio.gather(*tasks, return_exceptions=True)


def main():
    numbers = [500_000 + x for x in range(20)]
    start_time = time.time()
    result = asyncio.run(find_sums(numbers))
    end_time = time.time()
    duration = end_time - start_time
    print(f"Result {list(result)}")
    print(f"Duration {duration} seconds")


if __name__ == "__main__":
    main()
