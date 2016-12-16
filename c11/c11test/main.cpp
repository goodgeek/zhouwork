#include <iostream>
#include "base.h"
#include <vector>
#include <memory>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename T = int>
class Store {
public:
    typename std::vector<T>::size_type st;
    Store& operator=(const Store& s);
    void push(const T& v);
    T& pop();
    int getSize();
    bool empty();
private:
    std::vector<T> pBox;
    static int ctr;
};

template<typename T>
void Store<T>::push(const T& v)
{
    pBox.push_back(v);
}

template<typename T>
T& Store<T>::pop()
{
    if (pBox.size() > 0)
        return pBox.back();
}

template<typename T>
Store<T>& Store<T>::operator=(const Store &s)
{
    
}

template<typename T = int> using storeAny = Store<T>;

int main(int argc, char *argv[])
{
    storeAny<> a;

    a.push(10);

    return 0;
}

