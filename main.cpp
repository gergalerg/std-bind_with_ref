#include <iostream>


struct Stack {
    int data;
    enum { FIRST = 50, SECOND };
    Stack() : data(FIRST) {}
    Stack(int i) : data(i) {}
    void printer() { std::cout << "Non-const stack data = " << data << "\n"; }
    void printer() const { std::cout << "stack data = " << data << "\n"; }
    const struct Stack& create() { struct Stack* s1  = new struct Stack(); struct Stack& s2 = *s1; return s2; }
    const struct Stack& create(int i) { struct Stack* s1  = new struct Stack(i); struct Stack& s2 = *s1; return s2; }
};

typedef Stack& stack;

char* Function1() { 
return "Some text\n"; 
}

int main(int argc, char const *argv[])
{
    Function1();
    struct Stack s1(4444);
    s1.printer();

    const struct Stack& s2 = s1.create(222333);
    s2.printer();
    return 0;
}

