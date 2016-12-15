#include <iostream>
#include "base.h"
#include <vector>
#include <memory>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class Store {
public:
    Store& operator=(const Store& s);
    void push(const T& v);
    T& pop();
    int getSize();
    bool empty();
private:
    std::vector<T> pBox;
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

int main(int argc, char *argv[])
{
    Store<int> a;
    a.push(10);
    cout << a.pop() << endl;

    return 0;
}

