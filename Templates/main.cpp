#include "string.h"


int main(int argc, char const *argv[])
{
    std::unique_ptr<int> foo {new int{20}};
    std::unique_ptr<int> bar{new int{30}};

    using std::swap;
    foo.swap(bar);
    std::cout << *foo << "\n" << *bar << "\n";
    return 0;

}