from pytest import mark


def fibo(n, memo=None):
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n == 1 or n == 2:
        return 1
    memo[n] = fibo(n-1, memo) + fibo(n-2, memo)
    return memo[n]


def test_correctness():
    assert fibo(1) == 1
    assert fibo(2) == 1
    assert fibo(3) == 2
    assert fibo(4) == 3
    assert fibo(5) == 5
    assert fibo(6) == 8
    assert fibo(7) == 13
    assert fibo(8) == 21
    assert fibo(9) == 34


@mark.timeout(0.1)
def test_performance():
    assert fibo(50) == 12586269025
