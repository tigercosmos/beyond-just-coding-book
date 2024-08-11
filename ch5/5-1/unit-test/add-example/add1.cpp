#include <iostream>

int add(int a, int b)
{
    return a + b;
}

void print_add(int a, int b)
{
    auto result = add(a, b);
    std::cout << result << std::endl;
}

int main()
{
    print_add(1, 2); // 3
    print_add(3, 4); // 7

    return 0;
}