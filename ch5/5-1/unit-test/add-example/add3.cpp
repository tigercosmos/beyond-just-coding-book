#include <iostream>

template <typename T1, typename T2>
double add(T1 a, T2 b)
{
    int sum_int = (a + b) * 100;
    int check_num = sum_int % 10;
    double round = check_num >= 5 ? 0.1 : 0;
    return (sum_int - check_num) / 100.0 + round;
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
    print_add(2, 2.55);    // 4.55 -> 4.6
    print_add(3.33, 4.44); // 7.77 -> 7.8

    print_add(4.19, 5.20); // 9.4
    print_add(4.10, 5.14); // 9.2

    return 0;
}