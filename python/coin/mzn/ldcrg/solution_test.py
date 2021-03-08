from pytest import mark
from solution import maximum_shipped_items

@mark.parametrize('containers, items, cargo_size, expected_load', [
    ([3, 1, 2], [1, 2, 3], 4, 9),
    ([1, 2, 3], [3, 2, 1], 3, 7),
    ([1, 2, 3], [3, 2, 1], 10, 10),
])
def test_correctness(containers, items, cargo_size, expected_load):
    assert maximum_shipped_items(
        containers, items, cargo_size) == expected_load
