#include <iostream>
#include "base.h"
#include <vector>
#include <memory>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Human {
public:
    Human() = default;
    Human(int i) : i_(i) {}
    Human(const Human &h) : i_(h.i_) {}
    Human& operator=(const Human &h) { i_ = h.i_; return *this; }
    int getNumber() const { return i_; }
    int setNumbar(int i) { i_ = i; }
    int operator() (int a) { return a + i_; }
    operator int() { return 20; }
private:
    int i_;
};

class Ch : public Human {
public:
    Ch(const Ch &h) : j_(h.j_) {}
    Ch& operator=(const Ch &h) { j_ = h.j_; return *this; }
    string showMessage() { return "message"; } 
private:
    int j_;
};

template<typename T>
int add(const T &t, const T &a)
{
    return a * t;
}

int main(int argc, char *argv[])
{
    Ch h;
    Ch h2;

    return 0;
}

