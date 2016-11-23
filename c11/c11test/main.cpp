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
#include <sys/time.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
    Base() = default;
    void ShowPrint() { return; }
};

void showMessage()
{
    cout << "hello world" << endl;
}

int main(int argc, char *argv[])
{
    std::map<int, string> vec;

    std::uniform_int_distribution<unsigned> u(100, 1000000);
    std::default_random_engine e(time(NULL));

    struct timeval startTime;

    gettimeofday(&startTime, NULL);

    for (int i = 0; i < 10000000; i++) {
        vec.insert({i, std::to_string(i)});
        //vec.push_back(u(e)); 
        //vec.insert_after(vec.end(), i);
        //vec.push_front(u(e));
        //vec.push_back(u(e)); 
    }


    cout << "Insert data ok" << endl;
    //std::sort(vec.begin(), vec.end());
    cout << "compleate " << endl;

    /*
    for (int i = 0; i < 100; i++) {
        cout << i << endl;
    }
    */

    struct timeval endTime;
    gettimeofday(&endTime, NULL);

    long sec = (endTime.tv_sec - startTime.tv_sec) * 1000 + (endTime.tv_usec - startTime.tv_usec) % 1000;
    cout << "msec: " << sec << endl;

    return 0;
}

