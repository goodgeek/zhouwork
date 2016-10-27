#include "sealbase.h"
#include <iostream>

SealBase::SealBase(int age, int *ptr, std::string name) :
    age_(age), ptr_(ptr), name_(name)
{
    std::cout << "构造函数" << std::endl;
}

SealBase::SealBase(const SealBase &base) :
    age_(base.age_), ptr_(base.ptr_), name_(base.name_)
{
    std::cout << "拷贝构造函数" << std::endl;
}

SealBase &SealBase::operator=(const SealBase &base)
{
    std::cout << "拷贝赋值函数" << std::endl;

    auto newp = new int(*base.ptr_);
    delete base.ptr_;

    age_ = base.age_;
    ptr_ = newp;
    name_ = base.name_;
    return *this;
}

SealBase::SealBase(SealBase &&base) noexcept :
    age_(base.age_), name_(base.name_)
{
    std::cout << "移动构造函数" << std::endl;
    ptr_ = nullptr;
}

SealBase &SealBase::operator=(SealBase &&base) noexcept
{
    std::cout << "移动赋值函数" << std::endl;
    if (this != &base) {
        delete ptr_;    

        age_ = base.age_;
        ptr_ = base.ptr_;
        name_ = base.name_;
        base.ptr_ = nullptr;
    }
    return *this;
}

SealBase::~SealBase()
{
    std::cout << "析构函数" << std::endl;
}

SealBase operator+(const SealBase &rv)
{
    SealBase sb = rv;
    return sb;
}

int SealBase::age() const
{
    return age_;
}

void SealBase::setAge(int age)
{
    age_ = age;
}

std::string SealBase::name() const
{
    return name_;
}

void SealBase::setName(std::string name)
{
    name_ = name;
}
