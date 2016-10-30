#include "test.h"
#include <iostream>
#include <string>
#include <deque>

int main(int argc, char const *argv[])
{
    std::deque<int> d(5);
    std::cout << d.size() << "\n";

    for (int i=0; i < 10;i++)
        d.push_front(i);
    std::cout << d.size() << "\n";
    return 0;
}

