#ifndef __SEALBASE_H__
#define __SEALBASE_H__

#include <string>

class SealBase 
{
public:
    SealBase() = default;
    SealBase(int age, int *ptr, std::string name);
    SealBase(const SealBase &base);
    SealBase &operator=(const SealBase &base);
    SealBase(SealBase &&base) noexcept;
    SealBase &operator=(SealBase &&base) noexcept;
    ~SealBase();
private:
    int age_;
    std::string name_;
    int *ptr_;
};

#endif
