
#include "foo.hpp"
int Foo::PublicSum(int a, int b)
{
    return a + b;
}

int Foo::_PrivateSum(int a, int b)
{
    return a + b;
}