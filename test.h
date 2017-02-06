#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <iostream>
#include <typeinfo>

class Visitor;

class Node {
public:
    virtual void accept(Visitor&) = 0;
};

class Expr : public Node {
public:
    void accept(Visitor&) override;
};

class Stmt : public Node {
public:
    void accept(Visitor&) override;
};

class Visitor {
public:
    virtual void accept(Expr&) = 0;
    virtual void accept(Stmt&) = 0;
};

class Do1_visitor : public Visitor {
    void accept(Expr&) { std::cout << "do1 to Expr\n"; }
    void accept(Stmt&) { std::cout << "do1 to Stmt\n"; }
};

class Do2_visitor : public Visitor {
    void accept(Expr&) { std::cout << "do2 to Expr\n"; }
    void accept(Stmt&) { std::cout << "do2 to Stmt\n"; }
};

class AA {
protected:
public:
    virtual void show() const = 0;
};

class BB : public AA {
    int data;
   public:
   BB() : data{1}  { } 
   BB(BB& b) { std::cout << "BB& b called\n"; }
   BB(const BB& b) { std::cout << "const BB& b called\n"; }
   BB(BB&& b) { std::cout << "Move called\n";  }
   void show() const { std::cout << data << " \n";}
};
#include "test.tpp"


#endif
