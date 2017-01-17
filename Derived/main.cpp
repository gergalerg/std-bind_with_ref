#include <iostream>
#include <string>
#include <list>


struct Error {
    Error(const std::string& s) { std::cout << "Error: " << s << "\n";}
};
struct Employee {
    std::string first, last;
    virtual void print() const { throw Error{"New Errror"}; }
};


struct Manager : public Employee {
    int level;
    void print() const noexcept override { std::cout << first << "  " << last << " "<< level <<"\n"; }
};

void printer(Employee * e) {
    e->print();
}

struct B1{
    virtual bool is_enabled() const = 0;
    virtual void print() const = 0;
};
struct S: B1{
    S(const int _x, std::string _s) : x{_x}, s{_s} {}
    int x;
    std::string s;
    bool is_enabled() const override { return false; }
    void print() const override {  std::cout << x << " name : " << s << "\n"; }
};
void print(B1* b) 
{
    b->print();
}

struct A {
    virtual void print() const = 0;
protected:
    int x;
};

struct B: public A{
    using A::x;
    B() { A::x = 10;}
    void print() const { std::cout << x << "\n"; }
};

struct Test {
    std::string s;
};
int main(int argc, char const *argv[])
{
    B b;
    b.print();
    return 0;
}