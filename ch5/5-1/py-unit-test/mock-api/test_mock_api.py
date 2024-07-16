def fetch_data(api_client):
    return api_client.get_data()


def test_fetch_data(mocker):
    mock_api_client = mocker.Mock()
    mock_api_client.get_data.return_value = {"key": "value"}

    result = fetch_data(mock_api_client)

    assert result == {"key": "value"}
    mock_api_client.get_data.assert_called_once()
