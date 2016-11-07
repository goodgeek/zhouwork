#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>
#include <iostream>

class Object
{
public:
    virtual void getObjName() = 0;
    Object(std::string objName, int age) :
        objName_(objName), age_(age) {}
    Object(const Object &rsh) : objName_(rsh.objName_), 
        age_(rsh.age_) {}
    ~Object() {}

    void showMessage() { std::cout << "message" << std::endl; }
private:
    std::string objName_;
    int age_;
};

class Widget : public Object
{
public:
    Widget(std::string name, int age, std::string title, int custNo) :
        Object(name, age), title_(title), custNo_(custNo) {}

    Widget(const Widget &rsh) : Object(rsh), title_(rsh.title_), custNo_(rsh.custNo_) 
    {
    }
    void getObjName() override { std::cout << "hello" << std::endl; }
private:
    std::string title_;
    int custNo_;
};


int main(int argc, char *argv[])
{
    
    return 0;
}
