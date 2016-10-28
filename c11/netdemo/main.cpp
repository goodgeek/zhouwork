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
    Quote(string name) : name_(name) {};

    string printName() const { return name_; }
private:
    string name_;
};

class D : public Quote 
{
public:
    D(string name) : Quote(name) {}
    string printName() const { return "I'm d"; }
};

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;

    return 0;
}

int main()
{
    D d("hello");
    auto a = d.printName();
    cout << a << endl;
    cout << "hello wrold" << endl;

    compare(5, 2);

    return 0;
}

