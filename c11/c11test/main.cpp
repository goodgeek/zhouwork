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
#include <bitset>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <typeinfo>
#include <random>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
    Base() = default;
    void ShowPrint() { return; }
};

int main(int argc, char *argv[])
{
    std::vector<string> strvec = {"hello", "what", "is", "your", "name"};
    std::sort(strvec.begin(), strvec.end());

    std::vector<string> str2vec(5);

    for (auto i : strvec) {
        cout << i << endl;
    }
    return 0;
}

