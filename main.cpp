#include "test.h"
#include <vector>
#include <utility>
void do_something(Shape& s1, Shape& s2)
{
    if (s1.intersect(s2)) {
        std::cout << "They intersect!\n"; 
    } else {
        std::cout << "They don't intersect!\n";
    }
}

void test(Triangle& t, Circle& c) {
    std::vector<std::pair<Shape*, Shape*>> vs{ {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c}  };
    for (auto p :vs)
        do_something(*p.first, *p.second);
}

struct AA {
    virtual void Show() const {std::cout << "AA::Show called\n"; }
};

struct BB : AA {
    void Show() const {std::cout << "BB::Show called\n"; }
};

struct CC : BB {
    void Show() const { std::cout << "CC::Show called\n"; }
};


void foo(AA& a, AA& b) 
{
    if (typeid(a) == typeid(b))
        std::cout << "They're equal!\n";
    else
        std::cout << "They're not\n";
}
int main(int argc, char const *argv[])
{
    CC cc;
    CC c2;
    BB bb;
    foo(bb, cc); 
    foo(cc, c2);

    return 0;
}