#include <iostream>
#include <string>

static int t = 0;

struct Foo{
    int _x, _y;
    int& _r = t;
    Foo& operator=(int x) { _x = x; return *this;}
    friend std::ostream& operator<<(std::ostream& os, const Foo& f);
} ss;

int main(int argc, char const *argv[])
{
    Foo f{3,4};
    std::cout << f;
    return 0;
}


std::ostream& operator<<(std::ostream& os, const Foo& f) { 
    os << f._x << "\t" << f._y << "\t" << f._r << "\n";
    return os;
}
