#include <iostream>
#include <string>
#include <memory>

class Operate
{
public:
    virtual ~Operate() = default;

    virtual double getResult() {}
    void setValueA(double valueA) { valueA_ = valueA; }
    void setValueB(double valueB) { valueB_ = valueB; }

protected:
    double valueA_ = 0.0;
    double valueB_ = 0.0;
};

class AddOperate : public Operate
{
public:
    double getResult() override
    {
        return valueA_ + valueB_;
    }
};

class DecOperate : public Operate
{
public:
    double getResult() override
    {
        return valueA_ - valueB_;
    }
};

class OperateFactory
{
public:
    static std::shared_ptr<Operate> createOperate(std::string opera)
    {
        std::shared_ptr<Operate> ptrOpera;

        if (opera == "+") {
            ptrOpera = std::make_shared<AddOperate>();
        }

        if (opera == "-") {
            ptrOpera = std::make_shared<DecOperate>();
        }

        return ptrOpera;
    }
};

int main()
{
    std::shared_ptr<Operate> ptr;

    ptr = OperateFactory::createOperate("-");
    ptr->setValueA(20);
    ptr->setValueB(30);
    double valueC = ptr->getResult();

    std::cout << "add value:" << valueC << std::endl;

    return 0;
}
