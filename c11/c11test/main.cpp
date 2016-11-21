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
    std::map<int, string> mp = {{1, "hello"}, {2, "jack"}, {3, "uptime"}};

    
    return 0;
}

