import pytest


@pytest.fixture
def db_connection():
    # Setup: 建立模擬資料庫連線
    connection = {"status": "connected"}
    yield connection
    # Teardown: 關閉模擬資料庫連線
    connection["status"] = "disconnected"


@pytest.fixture
def setup_file(tmp_path):
    # Setup: 建立暫時檔案
    file_path = tmp_path / "test_file.txt"
    file_path.write_text("Hello, pytest!")
    yield file_path
    # Teardown: 移除暫時檔案
    file_path.unlink()


def test_db_connection(db_connection, setup_file):
    assert db_connection["status"] == "connected"
    assert setup_file.read_text() == "Hello, pytest!"
