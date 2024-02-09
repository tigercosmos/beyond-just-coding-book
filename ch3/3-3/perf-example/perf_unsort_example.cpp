#include <algorithm>
#include <ctime>
#include <iostream>

int main()
{
    // 測試用陣列
    const int arr_len = 32768;
    int data[arr_len];

    for (int c = 0; c < arr_len; ++c)
        data[c] = std::rand() % 256;

    // 不進行排序

    long long sum = 0;

    for (int i = 0; i < 30000; ++i)
    {
        for (int c = 0; c < arr_len; ++c)
        {
            if (data[c] >= 128) // 故意選 256 一半
            {
                sum += data[c];
            }
        }
    }

    std::cout << "sum = " << sum << std::endl;
}