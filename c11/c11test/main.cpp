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

class Component
{
public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    void operation()
    {
        std::cout << "ssssss" << std::endl;
    }
};

class Decorator : public Component
{
public:
    void setComponent(std::shared_ptr<Component> ptr)
    {
        pComponent = ptr;
    }

    void operation() override
    {
        if (pComponent) {
            pComponent->operation();
        }
    }
protected:
    std::shared_ptr<Component> pComponent;
};

class ConcreteDecoreatorA : public Decorator
{
public:
    void operation() override
    {
        Decorator::operation();
        addedState = "New State";
        std::cout << "jtzssss" << std::endl;
    }
private:
    std::string addedState;
};

int main(int argc, char *argv[])
{
    
    return 0;
}

