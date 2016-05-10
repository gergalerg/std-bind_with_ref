#include <iostream>
#include <string>
#include <functional>

void f(int n1, int n2, const int& n3) {
    std::cout << n1 << " " << n2 << " " << n3 << " \n";
}
int main(int argc, char const *argv[])
{
    int n = 7;
    auto f1 = std::bind(f, std::placeholders::_2, std::placeholders::_1, std::cref(n));
    f1(1,2);
    return 0;
}