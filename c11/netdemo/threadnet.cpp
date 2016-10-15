#include "threadnet.h"
#include <thread>
#include <string>
#include <cstdio>

ThreadNet::ThreadNet()
{
}

void ThreadNet::startNet()
{
    int recvCount = 0;

    std::thread t1(
            [&](){ 
                printf("I'm thread\n"); 
                recvCount = 20;
            });
    t1.join();

    printf("Receive: %d\n", recvCount);
}
