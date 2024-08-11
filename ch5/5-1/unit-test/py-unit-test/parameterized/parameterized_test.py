import pytest


def add(a, b):
    return a + b


@pytest.mark.parametrize(
    "x, y, result", [(1, 2, 3), (2, 3, 5), (3, 4, 7), (4, 5, 9)]
)
def test_add(x, y, result):
    assert add(x, y) == result
