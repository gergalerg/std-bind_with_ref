#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

template<typename Iter>
void forward(Iter p, int n)
{
    while (n > 0)
        *p++ = --n;
}

template <typename BDIter>
void alg(BDIter, BDIter, std::bidirectional_iterator_tag)
{
    std::cout << "alg() called for bidirectional_iterator_tag\n";
}

template <typename RAIter>
void alg(RAIter, RAIter, std::random_access_iterator_tag)
{
    std::cout << "alg() called for random_access_iterator_tag\n";
}

template <typename Iter>
void alg(Iter first, Iter last)
{
    alg(first, last, typename std::iterator_traits<Iter>::iterator_category());
}

template <typename Iter>
void advance_helper(Iter p, int n, std::random_access_iterator_tag)
{
    p += n;
    *p = 10;
}

template <typename Iter>
void advance_helper(Iter p, int n, std::forward_iterator_tag)
{
    if (0 < n) {
        while (n--) ++p;
        *p = 33;
    }
    else if (n < 0) {
        while (n++) --p;
        *p = 33;
    }
}

template <typename Iter>
void advance(Iter p, int n)
{
    advance_helper(p, n, typename std::iterator_traits<Iter>::iterator_category());
}
template <typename It>
void print_iter(It first)
{
    typename std::iterator_traits<It>::value_type tmp = *first;
    std::cout << tmp; 
}

int main(int argc, char const *argv[])
{

    std::vector<int> v(10);
    std::vector<int>::iterator it = v.begin();
    std::random_access_iterator_tag ra;
    advance_helper(it, 3, ra);

    for (auto& x: v) std::cout << x << "\t";
    std::cout << "\n\n";

    std::forward_iterator_tag ft;
    std::list<int> l(10);
    std::list<int>::iterator li = l.begin();
    for (auto& x: l) std::cout << x << "\t";
    std::cout << "\n\n";
    advance_helper(li, -5, ft);
    for (auto& x: l) std::cout << x << "\t";

    return 0;

}
