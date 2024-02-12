#include <algorithm>
#include <ctime>
#include <iostream>
#include <chrono>

#define LOOP_NUM 3000

int main()
{
    auto startTime = std::chrono::high_resolution_clock::now();

    // 測試用陣列
    const int arr_len = 32768;
    int data[arr_len];

    for (int c = 0; c < arr_len; ++c)
        data[c] = std::rand() % 256;

    std::sort(data, data + arr_len); // 進行排序

    long long sum = 0;

    for (int i = 0; i < LOOP_NUM; ++i)
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
    std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() - startTime;
    std::cout << "elapsed time = " << elapsedTime.count() << " seconds" << std::endl;
}