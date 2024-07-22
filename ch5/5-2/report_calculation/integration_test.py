from data_provider import get_data
from reporter import generate_report


def test_integration():
    # data_provider 負責給資料
    data = get_data()

    # reporter 負責處理資料
    report = generate_report(data)

    # 驗證 reporter 的結果
    expected_report = [
        {"a": 10, "b": 5, "add": 15, "subtract": 5, "multiply": 50, "divide": 2.0},
        {"a": 20, "b": 10, "add": 30, "subtract": 10, "multiply": 200, "divide": 2.0},
        {"a": 15, "b": 5, "add": 20, "subtract": 10, "multiply": 75, "divide": 3.0},
        {"a": 30, "b": 10, "add": 40, "subtract": 20, "multiply": 300, "divide": 3.0},
    ]

    assert report == expected_report, f"Expected {expected_report}, but got {report}"
