from pytest import mark


def fibo(n, memo=None):
    table = [0] * (n + 2)
    table[1] = 1
    for i in range(0, n):
        table[i+1] += table[i]
        table[i+2] += table[i]
    return table[n]


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
