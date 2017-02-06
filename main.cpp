#include "test.h"
#include <vector>
#include <utility>

void foo(Node* n, Visitor* v) {
    std::vector<std::pair<Node*, Visitor*>> vn { { n, v}, {n,v}, {n,v} };
    for (auto x : vn)
        x.first->accept(*x.second);
}

int main(int argc, char const *argv[])
{
    Expr* e = new Expr{}; 
    Stmt* s = new Stmt{};
    Do1_visitor* d1 = new Do1_visitor{};
    Do2_visitor* d2 = new Do2_visitor{};

    foo(e, d1);
    foo(e, d2);
    BB bb;
    BB bb2 = static_cast<BB&&>(bb);
    bb.show();

    return 0;
}