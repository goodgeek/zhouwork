#ifndef __BASH_H__
#define __BASH_H__

#include <string>

class Human;

class Base {
public:
    friend void swap(Base &l, Base &r);
    Base(std::string name, int age, Human *human);

    Base(const Base &b);
    Base& operator=(const Base &b);
    Base(Base &&b) noexcept;
    Base& operator=(Base &&b) noexcept;
    ~Base();

    std::string getName() const { return name_; }
private:
    std::string name_;
    int age_;
    Human *human_;
};

#endif
