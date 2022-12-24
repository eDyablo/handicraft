"""
Largest palindrome product

https://projecteuler.net/problem=3

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
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

    return max(filter(lambda n: is_palindromic(n), products))


print(solution())
