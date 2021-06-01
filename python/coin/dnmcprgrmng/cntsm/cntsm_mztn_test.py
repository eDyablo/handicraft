from pytest import mark


def count_sum(target: int, numbers: list[int], selected=0, memo=None) -> int:
    if memo is None:
        memo = {}
    key = target * len(numbers) + selected
    if key in memo:
        return memo[key]
    if target == 0:
        return 1
    if target < 0:
        return 0
    if selected >= len(numbers):
        return 0
    memo[key] = count_sum(target - numbers[selected], numbers,
                          selected, memo) + count_sum(target, numbers, selected+1, memo)
    return memo[key]


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
