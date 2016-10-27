#include <unistd.h>
#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <time.h>
#include "tcpserver.h"
#include "threadnet.h"
#include "sealbase.h"
#include <iostream>
#include <string>
using namespace std;

class Quote 
{
public:
    Quote() = default;
    Quote(string name) : name_(name) {};

    string printName() const { return name_; }
private:
    string name_;
};

class D : public Quote 
{
public:
    D() = default; 
};

int main()
{
    D d;
    auto a = d.printName();
    cout << a << endl;

    return 0;
}
