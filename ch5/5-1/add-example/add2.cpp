#include <iostream>

template <typename T1, typename T2>
auto add(T1 a, T2 b)
{
    return a + b;
}

template <typename T1, typename T2>
void print_add(T1 a, T2 b)
{
    auto result = add(a, b);
    std::cout << result << std::endl;
}

int main()
{
    print_add(1, 2); // 3
    print_add(3, 4); // 7

    print_add(0.1, 1.1);   // 1.2
    print_add(2, 2.55);    // 4.55
    print_add(3.33, 4.44); // 7.77

    return 0;
}