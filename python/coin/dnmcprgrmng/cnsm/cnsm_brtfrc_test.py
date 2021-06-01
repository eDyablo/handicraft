from pytest import mark


def can_sum(target, numbers, memo=None):
    if target == 0:
        return True
    if target < 0:
        return False
    for number in numbers:
        if can_sum(target - number, numbers, memo):
            return True
    return False


def test_correctness():
    assert can_sum(0, []) == True
    assert can_sum(1, [1]) == True
    assert can_sum(1, [2]) == False
    assert can_sum(7, [2, 3]) == True
    assert can_sum(7, [5, 3, 4, 7]) == True
    assert can_sum(7, [2, 4]) == False
    assert can_sum(8, [2, 3, 5]) == True
