#include "test.h"

std::unique_ptr<Ival_box> create() { 
    std::unique_ptr<Ival_box> p1 { new Ival_slider{0,5}};
    return p1;
};
int main(int argc, char const *argv[])
{
    std::unique_ptr<Ival_box> p1 = create();
    p1->prompt();
    std::cout << std::boolalpha;
    std::cout << p1->was_changed() <<'\n';
    return 0;
}
