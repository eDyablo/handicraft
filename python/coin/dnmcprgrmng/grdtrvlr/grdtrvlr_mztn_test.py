from pytest import mark


def count_travel_ways(width, height, memo=None):
    if memo is None:
        memo = {}
    key = f'{width},{height}'
    if key in memo:
        return memo[key]
    if width == 0 or height == 0:
        return 0
    if width == 1 or height == 1:
        return 1
    memo[key] = count_travel_ways(
        width-1, height, memo) + count_travel_ways(width, height-1, memo)
    return memo[key]


def test_correctness():
    assert count_travel_ways(0, 0) == 0
    assert count_travel_ways(1, 1) == 1
    assert count_travel_ways(1, 0) == 0
    assert count_travel_ways(0, 1) == 0
    assert count_travel_ways(1, 2) == 1
    assert count_travel_ways(2, 1) == 1
    assert count_travel_ways(2, 2) == 2
    assert count_travel_ways(3, 2) == 3
    assert count_travel_ways(2, 3) == 3


@mark.timeout(0.1)
def test_performance():
    assert count_travel_ways(18, 18) == 2333606220
