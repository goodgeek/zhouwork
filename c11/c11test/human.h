#ifndef __HUMAN_H__
#define __HUMAN_H__

#include <string>

class Human {
public:
    Human(std::string name) : name_(name) {}
    std::string getName() const { return name_; }
private:
    std::string name_;
};

#endif
