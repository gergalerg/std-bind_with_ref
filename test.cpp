#include "test.h"
#include <iostream>
#include <vector>
#include <list>
#include <numeric>

static int n = 0;

struct C{
    explicit C(int) {}
    C(const C&) { std::cout << "Ctor called\n"; ++n; }
};


struct Tracer {
    std::string mess;
    Tracer(const std::string& s) : mess{s} { std::clog << mess << "\n"; }
    ~Tracer() { std::clog << "~" << mess; }
};
template <typename T>
void f(const std::vector<T>& v)
{
    Tracer tr{"in f()\n"};
    for (auto x: v) {
        Tracer tr {std::string{"v loop "} + std::to_string(x) + '\n'};
    }
    std::cout << "End \n";
}

template <typename T, int N>
class S{
public:
    S();
    void printer();
private:
    class Bad_size{};
    std::vector<T> elem; // elem points to an array of sz doubles
    int sz; // sz is non-negative
};


template <typename T, int N>
S<T,N>::S() : elem(N) {  std::iota(elem.begin(), elem.end(), -4); };

template <typename T, int N>
void S<T,N>::printer()  { for (auto& x: elem) std::cout << x << "\t"; std::cout << "\n"; };


int main(int argc, char const *argv[])
{
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::list<int>::iterator> v;
    std::iota(v.begin(), v.end(), l.begin());

    int foo[] = {1,2,3,4,5};
    auto it  = std::begin(foo);
    std::cout << it << "\n";
    std::cout << ++it << "\n";
    std::cout << *std::end(foo);
    return 0;
}




