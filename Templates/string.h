#ifndef _string_h_
#define _string_h_

#include <iostream>
#include <map>
#include <type_traits>

template <typename C>
class String {
public:
    String() : sz{0} { ptr = new C[short_max]; C* beg= ptr; while (++beg<ptr+sz) *beg= 'a'; }
    explicit String(const C*);
    String(const String&);
    String operator=(const String&);
    void Print() { std::cout << ptr << "\n" << "size = " << sz << "\n"; }

    C& operator[](int n) { return ptr[n]; }  // unchecked element access
    String& operator+=(C c){ ptr[sz] = c; ++sz; return *this; }                 // add C at end
private:
    static const int short_max = 15; // for the short string optimization
    int sz;
    C* ptr; // ptr points to sz Cs
};

template <typename T>
class Link;

template <typename T, typename A>
class List {
public:
    template<typename U,typename B>
    class Iterator {
        Link<T>* current_position;
    public:
    };
    Iterator<T,A> begin();
    Iterator<T,A> end();
};

template <typename T, typename A>
List<T,A>::Iterator<T,A> List<T,A>::begin() {};

template <typename T, typename A>
List<T,A>::Iterator<T,A> List<T,A>::end() {};

#endif