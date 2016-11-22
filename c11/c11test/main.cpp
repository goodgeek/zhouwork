#include <string>
#include <cstdio>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <typeinfo>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
    Base() = default;
    void ShowPrint() { return; }
};

std::string find(std::string v, std::vector<std::string> &vec);

int main(int argc, char *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    

    cout << typeid("hello").name() << endl;

    return 0;
}

