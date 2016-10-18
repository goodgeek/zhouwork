#include "sealbase.h"

SealBase::SealBase(int age, std::string name) :
    age_(age), name_(name)
{
}

SealBase::SealBase(const SealBase &base) :
    age_(base.age_), name_(base.name_)
{

}

SealBase& SealBase::operator=(const SealBase &base)
{
}

SealBase::SealBase(const SealBase &&base) noexcept :
    age_(base.age_), name_(base.name_)
{
    age_ = 0;
    name_ = "";
}

SealBase& SealBase::operator=(const SealBase &&base) noexcept
{
     
}

SealBase::~SealBase()
{
}
