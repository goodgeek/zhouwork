#include <string>
#include <cstdio>

template<typename T>

auto compare(const T &v1, const T &v2)
{
    return v1 + v2;
}

int main(int argc, char *argv[])
{
    auto i = compare(3.0, 5.2);
    printf("%f\n", i);    

    return 0;
}
