#include "threadfileread.h"
#include <unistd.h>

void  ThreadFileRead::setFd(int aFd)
{
    this->fd = aFd;
}


void ThreadFileRead::run()
{
    char buf[65536] = {0};

    while ((read(fd, buf, sizeof(buf))) > 0)
    {
        emit getMessage(buf);
    }
}
