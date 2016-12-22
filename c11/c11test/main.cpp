#include <iostream>
#include "base.h"
#include <vector>
#include <memory>
#include <map>
#include <type_traits>
#include <typeinfo>

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

template<typename T>
T add(const T &a, const T &b)
{
    return a + b;
}

template<> double add(const double &a, const double &b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    double a1 = 2.2;
    double a2 = 3.0;
    cout << add(a1, a2) << endl;

    if 1{
        std::cout << "hello wrold" << endl;
    }

    return 0;
}

