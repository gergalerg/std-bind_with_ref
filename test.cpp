#include <iostream>
#include <string>
#include <functional>

void f(int n1, int n2, const int& n3) {
    std::cout << n1 << " " << n2 << " " << n3 << " \n";
}

struct Foo {
    explicit Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_ + i << '\n'; }
    int num_;
};

int print_num(int i) {
    return i++;
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main(int argc, char const *argv[])
{
    int n = 7;

    std::function<void(int)> x = PrintNum();
    std::function<int (int)> t = std::bind(print_num, 4344);
    std::cout << t(0);
    //std::function<void(int)> f_display = PrintNum();
    return 0;
}