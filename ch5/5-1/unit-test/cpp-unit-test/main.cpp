#include <iostream>
#include "foo.hpp"

int main()
{
    Foo foo;
    std::cout << foo.public_sum(1, 3) << std::endl;
}