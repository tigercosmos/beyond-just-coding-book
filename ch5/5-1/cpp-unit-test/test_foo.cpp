#include "foo.hpp"
#include <gtest/gtest.h>

// 定義  test fixture class
class FooTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        foo = new Foo();
    }

    void TearDown() override
    {
        delete foo;
    }

    int CallPrivateSum(int a, int b)
    {
        return foo->_PrivateSum(a, b);
    }

    Foo *foo;
};

// 測試 Foo Public 可以直接使用 Foo
TEST(Foo, PublicSum)
{
    Foo foo;
    EXPECT_EQ(foo.PublicSum(1, 3), 4);
}

// 測試 Foo Private 我們要使用 FooTest 的測試環境
TEST_F(FooTest, PrivateSum)
{
    EXPECT_EQ(CallPrivateSum(3, 4), 7);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}