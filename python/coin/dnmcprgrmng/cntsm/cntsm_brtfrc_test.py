def count_sum(target, numbers, selected=0):
    if target == 0:
        return 1
    if target < 0:
        return 0
    if selected >= len(numbers):
        return 0
    return count_sum(target - numbers[selected], numbers, selected) + count_sum(target, numbers, selected+1)


def test_correctness():
    assert count_sum(0, [1, 2, 3]) == 1
    assert count_sum(1, [1]) == 1
    assert count_sum(1, [2]) == 0
    assert count_sum(2, [1, 2]) == 2
    assert count_sum(10, [1, 5, 10, 25]) == 4
    assert count_sum(25, [1, 5, 10, 25]) == 13
    assert count_sum(7, [7, 4, 3, 2]) == 3
