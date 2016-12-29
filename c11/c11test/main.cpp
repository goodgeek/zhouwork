#include <iostream>
#include "base.h"
#include <vector>
#include <memory>
#include <map>
#include <typeinfo>
#include <random>
#include <time.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class SubSystemOne
{
public:
    void MethodOne()
    {
        cout << "system one method" << endl;
    }
};

class SubSystemTwo
{
public:
    void MethodTwo()
    {
        cout << "system two method" << endl;
    }
};

class SubSystemThree
{
public:
    void MethodThree()
    {
        cout << "system three method" << endl;
    }
};

class SubSystemFour
{
public:
    void MethodFour()
    {
        cout << "system four method" << endl;
    }
};

class Facade
{
public:
    std::unique_ptr<SubSystemOne> onePtr;
    std::unique_ptr<SubSystemTwo> twoPtr;
    std::unique_ptr<SubSystemThree> threePtr;
    std::unique_ptr<SubSystemFour> fourPtr;

    Facade()
    {
        onePtr.reset(new SubSystemOne());
        twoPtr.reset(new SubSystemTwo());
        threePtr.reset(new SubSystemThree());
        fourPtr.reset(new SubSystemFour());
    }

    void methodA()
    {
        cout << "Method group A" << endl;
        onePtr->MethodOne();
        twoPtr->MethodTwo();
        fourPtr->MethodFour();
    }

    void methodB()
    {
        cout << "Method group B" << endl;
        twoPtr->MethodTwo();
        threePtr->MethodThree();
    }
};

int main(int argc, char *argv[])
{
    Facade face;

    face.methodA();
    face.methodB();

    return 0;
}

