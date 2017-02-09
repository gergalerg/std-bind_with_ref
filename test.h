#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>


template <typename T, typename Alloc>
class List; 

template <typename T>
class Link {
    template <typename U, typename A>
    friend class List;
    T val;
    Link* succ;
    Link* prev;
};

template<typename T>
class Iterator {
    Link<T>* curr_pos;
};

template <typename T, typename Alloc>
class List {
public:
    Iterator<T> begin();
    Iterator<T> end();
};

template<typename T, typename Alloc>
Iterator<T> List<T, Alloc>::begin() {auto p = new Iterator<T>{}; return *p;}

template<typename T, typename Alloc>
Iterator<T> List<T, Alloc>::end() {auto p  = new Iterator<T>{}; return *p;}

template <typename T>
class Vector;

template <typename T>
Vector<T> operator*(const Vector<T>& m, const Vector<T>& v) {
    std::cout<< "Friend func called vector\n";
    Vector<T> r;
    return r;
}
template <typename T>
class Vector {
public:
    Vector() = default;
    Vector(const Vector&) {std::cout << "Copy called\n";}
    Vector<T>& operator=(Vector<T> o) { std::cout << "Copy assign called\n"; return o;}
    friend Vector<T> operator*<>(const Vector<T>& m, const Vector<T>& v);
};

#include "test.tpp"

#endif
