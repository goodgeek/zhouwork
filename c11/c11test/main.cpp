#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>

class HasPtr final {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) 
        {}
    HasPtr(const HasPtr &ptr) :
        ps(ptr.ps), i(ptr.i), use(ptr.use) { ++*use; }
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr() 
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;

    if (--*use == 0) {
        delete ps;
        delete use;
    } 

    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    return *this;
}

int main(int argc, char *argv[])
{
    int i = 20;
    double j = 30.2;
    j = static_cast<int>(i);

    std::cout << "hello world" << std::endl;

    return 0;
}
