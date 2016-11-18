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

std::string find(std::string v, std::vector<std::string> &vec);

int main(int argc, char *argv[])
{
    std::map<int, string> dataMap;

    for (int i = 0; i < 100; i++) {
        auto ret = dataMap.insert({i, "hello"});    
        if (!ret.second) {
            cout << "Insert data failed: " << i << endl;
        }
    }

    printf("size: %d\n", dataMap.size());

    return 0;
}

