#include <iostream>
#include <string>
#include <utility>

enum class Printer_flags : char {
    ack = 1,
    empty=2,
    busy=4,
    out_of_black=8,
    out_of_color=16
};

constexpr int operator|(Printer_flags a, Printer_flags b)
{
    return (static_cast<int>(a)|static_cast<int>(b));
}

void test(Printer_flags f)
{
    switch(f){
        case Printer_flags::ack:
            std::cout << "case 1\n"; return;
        case Printer_flags::empty: return;
            std::cout << "case 2\n";
            // commented fall-through
    }
}
int main(int argc, char const *argv[])
{

    Printer_flags f2 = static_cast<Printer_flags>(2);
    Printer_flags a = Printer_flags::ack;
    Printer_flags black= Printer_flags::out_of_black;

    test(a);
    std::cout << static_cast<int>(a|f2);
    return 0;
}