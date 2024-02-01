// foo.cpp

#include "foo.hpp"
#include <iostream>
#include <vector>

// Constructor definition
Foo::Foo()
{
    std::cout << "Foo object created" << std::endl;
}

// Member function definition
void Foo::bar()
{
    std::cout << "Bar function called" << std::endl;

    constexpr size_t length = 100;
    std::vector<int> arr;
    arr.reserve(length);

    for (size_t i = 0; i < length; ++i)
    {
        arr.push_back(i);
    }

    // question: if we set 999999 to 101, we can print the value without crash, why?
    constexpr size_t targetIndex = 999999;

    std::cout << "arr only has " << arr.size() << " elements, but trying to access arr[" << targetIndex << "]" << std::endl;

    std::cout << arr[targetIndex] << std::endl; // will segmentation fault

    std::cout << "I will not be printed due to the crash." << std::endl;
}
