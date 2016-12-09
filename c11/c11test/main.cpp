#include <iostream>
#include "base.h"
#include "human.h"
#include <vector>
#include <memory>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    std::shared_ptr<Base> ptrBase = 
        std::make_shared<Base>("zhou", 30, new Human("j"));

    Base *ptrBase2 = new Base("jj", 20, new Human("jjj"));
    ptrBase.reset(ptrBase2);
    string name = ptrBase->getName();
    cout << "Name: " << name << endl; 

    string line;
    while (cin >> line) {
        if (line == "quit") 
            break;
    }

    return 0;
}

