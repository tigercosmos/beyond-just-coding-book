import pytest


@pytest.fixture
def setup_database():
    # 假設函式背後使用真的資料庫
    test_db = setup_test_database()
    yield test_db
    teardown_test_database(test_db)


@pytest.fixture
def setup_api_client():
    # 假設函式背後使用真的 API client
    api_client = setup_test_api_client()
    yield api_client
    teardown_test_api_client(api_client)


@pytest.mark.skip("僅示範整合測試，並不能真的執行")
def test_process_data_from_api(setup_database, setup_api_client):
    # 使用測試夾具建立資料庫和 API client，兩者都是真實的物件
    db = setup_database
    client = setup_api_client

    # 取得 API 資料並處理
    api_data = client.fetch("https://api.example.com/data")

    # 驗證 API 資料
    assert "key" in api_data

    # 用 my_module 模組處理資料（假設該模組存在）
    my_module.process_data(api_data)

    # 使用資料庫儲存資料
    db_result = db.store_data(api_data)

    # 驗證資料庫處理結果
    assert db_result == "{result: 'success'}"

    # 驗證資料庫內容
    data_in_db = db_result.get_data("key")
    assert data_in_db == {"key": "new_value"}
