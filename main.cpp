#include <iostream>
#include <vector>
#include "test.h"
#include <string>
#include <memory>
#include <utility>

struct A {
    A(int&& n) { std::cout << "rvalue overload  n = " << n << "\n"; }
    A(int& n) { std::cout << "lvalue overload  n = " << n << "\n"; }
    A(const int& n) { std::cout << "const n overload "; }
};

class B {
public:
    template<class T1>
    B(T1&& t1) :
        a1_{std::forward<T1>(t1)} {}
private:
    A a1_;
};

template<typename T>
using C = std::vector<T>;

int main(int argc, char const *argv[])
{
    using A = std::allocator<int>;
    int* elem;
    A alloc;
    elem = alloc.allocate(10);

    int x=10; 
    C<int> b = {1,2,3,4};
    std::cout << b.capacity() << "\n";
    b.reserve(20);
    std::cout << b.capacity() << "\n";
    b.shrink_to_fit();
    std::cout << b.capacity() << "\n";
    return 0;
}

