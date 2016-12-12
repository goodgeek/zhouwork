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
    int getNumber() const { return i_; }
    int setNumbar(int i) { i_ = i; }
    int operator() (int a) { return a + i_; }
    operator int() { return 20; }
private:
    int i_;
};

int main(int argc, char *argv[])
{
    Human h;
    Human s;
    cout << s + "" << endl; 

    return 0;
}

