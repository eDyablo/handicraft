from pytest import mark


def can_sum(target, numbers, memo=None):
    table = [False] * (target + 1)
    table[0] = True
    for sub_target in range(0, target):
        if table[sub_target]:
            for number in numbers:
                sum = sub_target+number
                if sum <= target:
                    table[sum] = True
    return table[target]


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
