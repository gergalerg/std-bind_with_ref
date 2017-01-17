#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <iostream>
#include <memory>
#include <future>

#include "test.tpp"

class Ival_box {
protected:
    int val;
    int low, high;
    bool changed{false};
public:
    Ival_box(int ll, int hh) : val{ll}, low{ll}, high{hh}{}
    Ival_box():val{0}, low{0}, high{10} {}

    virtual int get_value() { changed=false; return val;}
    virtual void set_value(int i) { changed=true; val=i;}
    virtual void reset_value(int i) { changed=false; val=i;}
    virtual void prompt() {std::cout << "Enter a number: "; std::cin >> val; set_value(val);}
    virtual bool was_changed() const { return changed; }

    virtual ~Ival_box() {}
};

class Ival_slider : public Ival_box{
public:
    Ival_slider() { Ival_box(); }
    Ival_slider(int ii, int jj) : Ival_box{ii, jj} {}
};
#endif
