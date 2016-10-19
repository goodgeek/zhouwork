#include <unistd.h>
#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <time.h>
#include "tcpserver.h"
#include "threadnet.h"
#include <array>
#include "sealbase.h"
#include <iostream>

int main()
{
    int i = 20;
    int &j = i;
    int &&k = std::move(i);

    std::cout << "i=" << i << std::endl; 
    std::cout << "j=" << j << std::endl;
    std::cout << "k=" << k << std::endl;
    std::cout << "i=" << i << std::endl; 
    return 0;
}
