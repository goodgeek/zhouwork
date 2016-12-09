#include "base.h"
#include "human.h"
#include <iostream>

inline void swap(Base &l, Base &r)
{
    using std::swap;
    swap(l.name_, r.name_);
    swap(l.age_, r.age_);
    swap(*l.human_, *r.human_);
}

Base::Base(std::string name, int age, Human *human) : 
    name_(name), age_(age), human_(human)
{
    std::cout << "Create object" << std::endl;
}

Base::Base(const Base &b) :
    name_(b.name_), age_(b.age_), 
    human_(new Human(b.human_->getName()))
{
    std::cout << "Copy init" << std::endl;
}

Base& Base::operator=(const Base &b)
{
    std::cout << "Copy assigmn" << std:: endl;
    name_ = b.name_;
    age_ = b.age_;
    
    return *this;
}

Base::~Base()
{
    std::cout << "Invoked destroy" << std::endl;
    delete human_;
}


