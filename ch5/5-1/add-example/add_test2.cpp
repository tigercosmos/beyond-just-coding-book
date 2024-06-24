#include <iostream>
#include <sstream>

template <typename T1, typename T2>
double add(T1 a, T2 b)
{
    int sum_int = (a + b) * 10;
    return sum_int/10.0;
}

template <typename T1, typename T2>
void assert_equal(T1 a, T2 b)
{
    if (a - b != 0)
    {
        std::stringstream ss;
        ss << "assert equal failed: " << a << " != " << b;
        throw std::runtime_error(ss.str());
    }
}

void test_add()
{
    assert_equal(add(1, 2), 3);
    assert_equal(add(3, 4), 7);
    assert_equal(add(0.1, 1.1), 1.2);
    assert_equal(add(2, 2.55), 4.5);
    assert_equal(add(3.33, 4.44), 7.7);
    assert_equal(add(4.19, 5.20), 9.3);
    assert_equal(add(4.10, 5.14), 9.2);

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    test_add();
    return 0;
}