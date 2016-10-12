#include <unistd.h>
#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <time.h>
#include "tcpserver.h"

int main()
{
    Logger *log = new Logger();
    log->logInfo("Start application...");

    TcpServer server;
    server.startServer();

    return 0;
}
