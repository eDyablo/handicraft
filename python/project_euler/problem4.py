"""
Largest palindrome product

https://projecteuler.net/problem=3

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

10000000a + 1000000b + 100000c + 10000d + 1000d + 100c + 10b + a
10000001a + 1000010b + 100100c + 11000d
11(909091a + 90910b + 9100c + 1000d)
"""


def solution():
    factors = ((a, b) for a in range(999, 99, -1) for b in range(a, 99, -1))

    products = (a * b for a, b in factors)

    def reversed(number):
        reversed = 0
        while number:
            reversed = reversed * 10 + number % 10
            number //= 10
        return reversed

    def is_palindromic(number):
        return reversed(number) == number

    return max(filter(lambda n: n % 11 == 0 and is_palindromic(n), products))


print(solution())
