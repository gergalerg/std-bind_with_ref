#include <iostream>
#include <memory>
#include <iterator>

template <class T, class A= std::allocator<T>>
class vector {
private:
    T* elem; //start of allocation
    T* space; // end of element sequence, start of space allocated for expansion
    T* last; // end of allocated space
    A alloc;  // allocator
public:
    using size_type = unsigned int;  // type used for vector sizes

    explicit vector(size_type n, const T& val = T(), const A& = A());

    vector(const vector& a);  // copy ctor
    vector& operator=(const vector& a); // copy assignment

    vector(vector&& a); // move ctor
    vector& operator=(vector&& a);  //move assignment

    size_type size() const { return space - elem; }
    size_type capacity() const { return last - elem; }
    void reserve(size_type n); // increase capacity to n

    void resize(size_type n, const T& ={}); //increase size to n
    void push_back(const T&);   // add an element at the end

    void printer() const { for(std::iterator<T> p = elem;p!=last; ++p) {std::cout << p<< "\t";}; std::cout << "\n"; }
};

int main(int argc, char const *argv[])
{
    vector<int> b{10};
    return 0;
}

template<class T, class A>
vector<T,A>::vector(size_type n, const T& val, const A& a)
    : alloc{a}   // copy the allocator
{
    elem = alloc.allocate(n);  // get memory for elements
    space = last = elem +n;    
    for (T* p = elem; p!=last; ++p)
        a.construct(p, val);    // construct copy of val in *p
}