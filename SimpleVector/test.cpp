#include <iostream>
#include <memory>

template<class T>
struct Foo {
    typedef T value_type;
    value_type little_int;
    value_type* p_int;
};
int main(int argc, char const *argv[])
{
    int i1 = true;
    std::cout << std::boolalpha << i1 << "\n";
    return 0;
}