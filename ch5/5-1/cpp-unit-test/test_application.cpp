#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Database interface
class Database
{
public:
    virtual ~Database() {}
    virtual bool connect(const std::string &url) = 0;
    virtual bool disconnect() = 0;
    virtual int query(const std::string &sql) = 0;
};

// Mock class
class MockDatabase : public Database
{
public:
    MOCK_METHOD(bool, connect, (const std::string &url), (override));
    MOCK_METHOD(bool, disconnect, (), (override));
    MOCK_METHOD(int, query, (const std::string &sql), (override));
};

// Class under test
class Application
{
public:
    Application(Database *db) : db_(db) {}

    bool initialize(const std::string &url)
    {
        return db_->connect(url);
    }

    int executeQuery(const std::string &sql)
    {
        return db_->query(sql);
    }

private:
    Database *db_;
};

// Tests
TEST(ApplicationTest, InitializeTest)
{
    MockDatabase mock_db;

    EXPECT_CALL(mock_db, connect("localhost")) // 模擬 connect()
        .Times(1)                              // 預期只會被呼叫一次
        .WillOnce(testing::Return(true));      // 只會回傳一次 true

    Application app(&mock_db);
    EXPECT_TRUE(app.initialize("localhost"));
}

TEST(ApplicationTest, ExecuteQueryTest)
{
    MockDatabase mock_db;

    EXPECT_CALL(mock_db, query(testing::_)) // 當 query 收到任意參數
        .Times(1)                           // 預期只會被呼叫一次
        .WillOnce(testing::Return(42));     // 回傳 42

    Application app(&mock_db);
    EXPECT_EQ(app.executeQuery("SELECT SUM(Cost) FROM Bills;"), 42);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
