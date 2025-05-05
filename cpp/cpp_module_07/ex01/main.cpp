#include "iter.hpp"
#include <iostream>
#include <string>

void twice(int const &n) 
{
    std::cout << n * 2 << std::endl;
}

void print(std::string &s) 
{
    std::cout << s << std::endl;
}

int main(void) 
{
    int array[] = {1, 2, 3, 4, 5};

    std::string strings[] = {"s1", "s2", "s3"};

    iter(array, 5, twice);

    iter(strings, 3, print);
}