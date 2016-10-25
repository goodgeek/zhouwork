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

    SealBase operator+(const SealBase &lv, const SealBase &rv);
    int operator() (int val) const;

    int age() const;
    void setAge(int age);
    std::string name() const;
    void setName(std::string name);
    
>>>>>>> d8169435f96ede79fe199a776d768d31aba983c3
private:
    int age_;
    std::string name_;
    int *ptr_;
};

#endif
