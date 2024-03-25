#include <iostream>

int main()
{
    std::string input;

    // Read input from stdin
    while (std::getline(std::cin, input))
    {
        // Output to stdout
        std::cout << "stdout: " << input << std::endl;

        // Output to stderr
        std::cerr << "stderr: " << input << std::endl;
    }

    return 0;
}