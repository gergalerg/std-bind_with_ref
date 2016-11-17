#include <memory>
#include <iostream>
#include <string>
#include <valarray>
#include <stddef.h>

template <class T>
struct Base
{
    void interface()
    {
        static_cast<T&>(*this).implementation();
    }
    void static_func()
    {
        typename T::static_sub_func();
    }
};

struct Derived : public Base<Derived>
{
    void implementation() { std::cout << "implementation\n"; }
    void static_sub_func() { std::cout << "static_sub_func\n";}
};

int main(int argc, char const *argv[])
{
    Base<Derived> b;
    b.interface();

    printf("Size = %lu\n", SIZE_MAX);
    return 0;
}