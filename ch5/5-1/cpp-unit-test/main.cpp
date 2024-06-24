#include <iostream>
#include "foo.hpp"

int main()
{
    Foo foo;
    std::cout << foo.PublicSum(1, 3) << std::endl;
}