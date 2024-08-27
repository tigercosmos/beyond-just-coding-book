#include <iostream>

struct  Foo
{
    void bar () {std::cout<<"Hello, World!"<<std::endl;}
};

int main()
{
    Foo * foo;
    foo->bar();
    return 0;
}
