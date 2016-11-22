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
#include <random>
#include <unistd.h>
#include <time.h>

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
    std::uniform_int_distribution<unsigned> u(10000, 99999);
    std::default_random_engine e;

    for (int i = 0; i < 50; i++) {
        cout << u(e) << endl;
    }

    return 0;
}

