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
#include <unordered_set>
#include <utility>
#include <typeinfo>
#include <random>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <algorithm>
#include <sys/time.h>
#include <functional>
#include <dirent.h>
#include <stack>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
    Base() = default;
    Base(std::initializer_list<string> li) {}
    string showMessage() { return "ok";}
private:
    string name;
};

int main(int argc, char *argv[])
{
    std::allocator<Base> alloc;
    auto p = alloc.allocate(5);
    auto q = p;
    alloc.construct(q++);
    while (q != p) {
        alloc.destroy(q--);
    }

    alloc.deallocate(p, 2);

    return 0;
}

