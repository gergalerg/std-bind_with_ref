#include "test.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 1;

    if (x!=1 || y != 1)
        std::cout << "Yes " << x << " " << y <<"\n";
    else
        std::cout << "NO" << x << " " << y <<"\n";
    return 0;
}





