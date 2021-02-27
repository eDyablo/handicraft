from pytest import mark, fixture
from qmriddle import solve


@mark.parametrize('riddle', [
    '?',
    '?b',
    '??',
    '???',
    'abc',
    'a?',
    'ab?',
    '?a',
    '??a',
    '??b',
    '??c',
    'a?a',
    'a?b',
    'a?c',
    'a?a?a',
    'a?a?b',
    'a?b?b',
    'a?b?c',
    '?a?b??c???d????',
    '?' * 13,
    '?' * 14,
    '?' * 26,
])
def test_solve(riddle):
    answer = solve(riddle)
    valid_symbols = all([ord('a') <= ord(symbol) <= ord('z')
                         for symbol in answer])
    no_repetitions = all([pair[0] != pair[1]
                          for pair in zip(answer[:], answer[1:])])
    assert len(answer) == len(riddle) and valid_symbols and no_repetitions


@fixture(scope="module", params=["a", "?", "a?", "?b", "a?c"])
def long_riddle(request):
    pattern = request.param
    return pattern * int(1000000 / len(pattern))


@mark.timeout(0.5)
def test_performance(long_riddle):
    solve(long_riddle)
