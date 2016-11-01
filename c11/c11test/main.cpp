#include <string>
#include <cstdio>
#include <memory>
#include <iostream>

class TestBase
{
public:
    enum Result { NoError, Success };

    TestBase(int age): age_(age) {}
    std::string showMessage() { return "hello"; }
    Result gotoZero() { return Success; }
private:
    int age_;
};

int main(int argc, char *argv[])
{
    std::shared_ptr<TestBase> ptrTestBase = std::make_shared<TestBase>(5);
    std::cout << "ptr count:" <<  ptrTestBase.use_count() << std::endl;
    std::cout << ptrTestBase.get()->showMessage() << std::endl;
    std::cout << ptrTestBase.get()->gotoZero() << std::endl;

    return 0;
}
