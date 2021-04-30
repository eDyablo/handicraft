from pytest import mark
from grdtrvlr import count_travel_ways


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
