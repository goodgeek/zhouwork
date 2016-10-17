#ifndef __SEALBASE_H__
#define __SEALBASE_H__

#include <string>

class SealBase 
{
public:
    SealBase(int age, std::string name);
    SealBase(const SealBase& base);
    SealBase& operator=(const SealBase& base);
    ~SealBase();
private:
    int age_;
    std::string name_;
};

#endif
