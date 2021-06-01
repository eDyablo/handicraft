from pytest import mark


def count_sum(target, numbers, selected=0, memo=None):
    table = [0] * (target+1)
    table[0] = 1
    for number in numbers:
        for sub_target in range(number, target+1):
            table[sub_target] += table[sub_target-number]
    return table[target]


def test_correctness():
    assert count_sum(0, [1, 2, 3]) == 1
    assert count_sum(1, [1]) == 1
    assert count_sum(1, [2]) == 0
    assert count_sum(2, [1, 2]) == 2
    assert count_sum(10, [1, 5, 10, 25]) == 4
    assert count_sum(25, [1, 5, 10, 25]) == 13
    assert count_sum(7, [7, 4, 3, 2]) == 3


@mark.timeout(0.1)
def test_performance():
    assert count_sum(1000, [3]*10) == 0
