#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>
#include <iostream>

class Human
{
public:
    typedef int int8;
    Human() = default;
    Human(std::string name, int age) : 
        name_(name), age_(age) {}
    virtual std::string printName()
    { std::cout << "base" << std::endl; return name_; }
    virtual auto getAge() -> int8;
private:
    std::string name_;
protected:
    int age_;
};

auto Human::getAge() -> int8
{
    return 20;
}

class Phone : public Human
{
public:
    std::string printName() override 
    { std::cout << "jack" << std::endl; return "jack"; } 
    void setAge(int age) { age_ = age; }
private:
    int j;
};

void PrintHuman(Human &human)
{
    std::cout << human.printName() << std::endl;
}

class object
{
public:
    virtual void getObjName() = 0;
    void showMessage() { std::cout << "message" << std::endl; }
private:
    std::string objName;
};

class widget : private object
{
public:
    void getObjName() { std::cout << "hello" << std::endl; }
};

int main(int argc, char *argv[])
{
    widget wd;
    wd.showMessage();
    return 0;
}
