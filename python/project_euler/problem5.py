"""
Smallest multiply

https://projecteuler.net/problem=5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
"""

from problem3 import factorize
from itertools import chain


def solution():
    return list(factorize(d) for d in range(20, 1, -1))


print(solution())
