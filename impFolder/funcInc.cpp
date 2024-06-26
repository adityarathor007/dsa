#include <iostream>

void funcCheck(int count)
{
    // Function implementation
    std::cout << "Inside move function, count is " << count << std::endl;
}

int main()
{
    int count = 0;

    // Call the move function with incremented count
    funcCheck(count += 1);

    // Print count after function call
    std::cout << "The value of count after move function call is " << count << std::endl;

    return 0;
}
