from pytest import mark
from cnsm import can_sum


def test_correctness():
    assert can_sum(0, []) == True
    assert can_sum(1, [1]) == True
    assert can_sum(1, [2]) == False
    assert can_sum(7, [2, 3]) == True
    assert can_sum(7, [5, 3, 4, 7]) == True
    assert can_sum(7, [2, 4]) == False
    assert can_sum(8, [2, 3, 5]) == True


@mark.timeout(0.1)
def test_performance():
    assert can_sum(300, [7, 14]) == False
