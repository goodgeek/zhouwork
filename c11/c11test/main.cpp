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

using std::string;
using std::cout;
using std::endl;

std::string find(std::string v, std::vector<std::string> &vec);

class Object
{
public:
    virtual void getObjName() = 0;
    Object(std::string objName, int age) :
        objName_(objName), age_(age) {}
    Object(const Object &rsh) : objName_(rsh.objName_), 
        age_(rsh.age_) {}
    ~Object() {}

    void showMessage() { std::cout << "message" << std::endl; }
private:
    std::string objName_;
    int age_;
};

class Widget : public Object
{
public:
    Widget(std::string name, int age, std::string title, int custNo) :
        Object(name, age), title_(title), custNo_(custNo) {}

    Widget(const Widget &rsh) : Object(rsh), title_(rsh.title_), custNo_(rsh.custNo_) 
    {
    }
    void getObjName() override { std::cout << "hello" << std::endl; }
private:
    std::string title_;
    int custNo_;
};


template <typename T>
int compare(const T &a, const T &b)
{
    if (a < b) return -1;
    if (b < a) return 1; 
} 

template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }

    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    T& back();
    T& operator[] (size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};


int main(int argc, char *argv[])
{
    std::fstream f("/root/11.txt", std::fstream::in);

    std::vector<std::string> strVec;

    std::string line;
    while (std::getline(f, line)) {
        if (line != "") {
            strVec.push_back(line);
        }
    }

    cout << "size:" << strVec.size() << endl;

    while(std::getline(std::cin, line)) {
        if (line == "quit") {
            break;
        }

        auto str = find(line, strVec);
        if (str != "") {
            std::cout << "find: " << str << std::endl;
        }
    }

    return 0;
}

std::string find(std::string v, std::vector<std::string> &vec)
{
    for (auto i : vec) {
        if (i == v) {
            return i;
        }
    } 

    return "";
}

std::vector<std::string> split(std::string str, std::string dem)
{
    
}
