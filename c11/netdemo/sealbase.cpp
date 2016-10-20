#include "sealbase.h"

SealBase::SealBase(int age, int *ptr, std::string name) :
    age_(age), ptr_(ptr), name_(name)
{
}

SealBase::SealBase(const SealBase &base) :
    age_(base.age_), name_(base.name_)
{
    
}

SealBase &SealBase::operator=(const SealBase &base)
{
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
    ptr_ = nullptr;
}

SealBase &SealBase::operator=(SealBase &&base) noexcept
{
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
}

