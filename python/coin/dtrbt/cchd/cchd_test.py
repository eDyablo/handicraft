'''
You need to write a caching decorator that can be applied to both functions and methods.
When applied, a wrapped function should calculate its output only once for a given set of parameters.
If passed again, a cached value should be returned instead.
'''
from cchd import cached


def test_correctness():
    call_log = []

    @cached
    def calc(a, b, c):
        call_log.append('calc')
        return a + b * c
    assert calc(1, 2, 3) == 7
    assert calc(1, 2, 3) == 7
    assert calc(2, 3, 1) == 5
    assert calc(3, 2, 1) == 5
    assert calc(2, 3, 1) == 5
    assert calc(3, 2, 1) == 5
    assert calc('1', '2', 3) == '1222'
    assert calc('1', 2, '3') == '133'
    assert len(call_log) == 5
