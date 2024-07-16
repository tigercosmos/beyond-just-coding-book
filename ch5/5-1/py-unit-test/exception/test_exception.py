import pytest


class Calculator:
    def divide(self, a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero")
        return a / b


def test_divide_by_zero():
    calc = Calculator()

    # 檢查是否為 ValueError 例外
    with pytest.raises(ValueError) as excinfo:
        calc.divide(10, 0)

    # 確認例外訊息是否正確
    assert str(excinfo.value) == "Cannot divide by zero"


def test_divide():
    calc = Calculator()

    result = calc.divide(10, 2)  # 一般測試
    assert result == 5
