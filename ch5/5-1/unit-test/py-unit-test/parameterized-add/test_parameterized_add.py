import pytest


def add(a, b):
    return a + b


@pytest.mark.parametrize(
    "x, y, result", [(2, 3, 5), (1, 1, 2), (0, 0, 0), (-1, -1, -2)]
)
def test_add(x, y, result):
    assert add(x, y) == result
