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

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
    Base() : name("zhou"), address("zj"), age(30) {}
    void ShowPrint() { return; }
private:
    string name;
    string address;
    int age;
};

int main(int argc, char *argv[])
{
    std::list<std::unique_ptr<Base>> vec;

    std::uniform_int_distribution<unsigned> u(100, 1000000);
    std::default_random_engine e(time(NULL));

    struct timeval startTime;
    gettimeofday(&startTime, NULL);

    for (int i = 0; i < 50000000; i++) {
        std::unique_ptr<Base> base(new Base());
        vec.push_back(std::move(base));
    }

    cout << "Insert data ok" << endl;

    struct timeval endTime;
    gettimeofday(&endTime, NULL);

    long sec = (endTime.tv_sec - startTime.tv_sec) * 1000 + 
        (endTime.tv_usec - startTime.tv_usec) % 1000;
    cout << "msec: " << sec << endl;

    cout << "Start reset" << endl;
    
    for (int i = 0; i < 50000000; i++) {
        vec.pop_back();
    }

    string line;
    while (cin >> line) {
        if (line == "quit")
            break;

    }
    
    return 0;
}

