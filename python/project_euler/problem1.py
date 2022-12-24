"""
Multiples of 3 or 5

https://projecteuler.net/problem=1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""

from itertools import count, cycle, islice
from functools import reduce

threes = cycle([0, 0, 1])
fives = cycle([0, 0, 0, 0, 1])
numbers = count(1)

sequence = ((three | five) * number
            for three, five, number in zip(threes, fives, numbers))

print(reduce(lambda x, y: x + y, islice(sequence, 999)))
