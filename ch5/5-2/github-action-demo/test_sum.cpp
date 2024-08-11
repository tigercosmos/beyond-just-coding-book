#include <iostream>

int sum(int a, int b);

int main()
{
    if (sum(2, 3) != 5)
    {
        std::cout << "Test failed!" << std::endl;
        return 1;
    }

    std::cout << "Test passed!" << std::endl;
    return 0;
}