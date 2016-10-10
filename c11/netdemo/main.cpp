#include <unistd.h>
#include <stdio.h>
#include "logger.h"

int main()
{
    Logger *log = new Logger();
    log->logInfo("hello");

    printf("hello world!\n");
    return 0;
}
