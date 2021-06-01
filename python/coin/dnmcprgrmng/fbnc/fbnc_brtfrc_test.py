from pytest import mark


def fibo(n):
    if n < 3:
        return 1
    return fibo(n - 1) + fibo(n - 2)


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
