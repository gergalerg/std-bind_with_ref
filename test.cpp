#include "test.h"
#include <iostream>

struct C{
    int day;
};

bool operator==(C a, C b)
{
    return a.day == b.day;
}

C& operator++(C& c) { ++c.day; return c; }

int main(int argc, char const *argv[])
{
    C first {.day=3};
    C second { .day=3};
    bool res = first == second;
    std::cout << std::boolalpha;
    std::cout << res << "\n";
    ++first;
    std::cout << first.day << "\n";
    return 0;
}




