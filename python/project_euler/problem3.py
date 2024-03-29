"""
Largest prime factor

https://projecteuler.net/problem=3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
"""

from functools import reduce
from math import floor, sqrt


def factorize(number):
    primes = []

    for factor in range(2, floor(sqrt(number))+1):
        if number % factor == 0:
            primes.append(factor)
            while number % factor == 0:
                number //= factor

    if number > 1:
        primes.append(number)

    return primes


if __name__ == "__main__":
    number = 600851475143
    primes = factorize(number)
    assert reduce(lambda a, b: a*b, primes) == number
    print(primes[-1])
