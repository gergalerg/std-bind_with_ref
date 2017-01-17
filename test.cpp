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

class Window {
public:
    virtual void draw();
};

class Window_with_menu : public Window {
protected:
    void own_draw() { std::cout << "Window_with_menu::own_draw()\n"; }
public:
    Window_with_menu() = default;
    Window_with_menu(const Window_with_menu&) { std::cout << "Move op called\n"; }
    void draw() override { Window::draw(); own_draw(); }
};

void Window::draw() {std::cout << "Window::draw()\n"; }

void caller(Window& w) {
    w.draw();
}
auto operator"" _s(const char* c) {
    return c;
}
int main(int argc, char const *argv[])
{
    Window_with_menu m;
    caller(m);
    return 0;
}





