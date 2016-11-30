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
    std::vector<int> vec;
    std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<unsigned> u(1, 100000);

    for (int i = 0; i < 10000000; i++) {
        vec.push_back(u(e));
    }

    struct timeval startTime, endTime;
    gettimeofday(&startTime, nullptr);

    std::sort(vec.begin(), vec.end());

    gettimeofday(&endTime, nullptr);
    long elps = (endTime.tv_sec - startTime.tv_sec) * 1000  + 
        (endTime.tv_usec - startTime.tv_usec) % 1000;
    cout << "mSec Time:" << elps << endl;

    return 0;
}

