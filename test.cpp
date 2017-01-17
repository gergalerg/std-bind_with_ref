#include <iostream>
#include <string>
#include <typeinfo>

int& ref() { 
    int* res = new int{3};
    return *res;
}

template <typename T>
void print(T& t) {
    std::cout << typeid(t).name() << '\n';
}

template <typename T>
void print(T&& t) {
    std::cout << typeid(t).name() << '\n';
}
struct A {
    A() = delete;
    A(int _m) : m(_m) { std::cout << "A(int) called\n"; }
    virtual void read() = 0;
protected:
    int m;

    A(A&) = delete;
    A& operator=(const A&) = delete;
};

class Trans : public virtual A {
public:
    Trans() = delete;
    Trans(int i) : A{i} {}
    void read() override { std::cout << "m = " << m << '\n'; } 
};

class Receiver : public virtual A {
public:
    Receiver() = delete;
    Receiver(int i) : A{i} { std::cout << "Receiver(int) called\n"; }
    void read() override { std::cout << "Rec::m = " << m << '\n'; }
};

class Radio : public Trans, public Receiver {
public:
    /*
    using Trans::Trans;
    using Receiver::Receiver;
    */
    Radio() : A{0}, Trans{0}, Receiver{0} {}
    Radio(int i) : A{i}, Trans{0}, Receiver{0} {}
    void read() override final { std::cout << "Radio::m = " << m << '\n';}
};

int main(int argc, char const *argv[])
{
    Radio r(10);
    r.read();

    return 0;
}





