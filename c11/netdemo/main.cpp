#include <unistd.h>
#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <time.h>
#include "tcpserver.h"
#include "threadnet.h"

int main()
{
    Logger *log = new Logger();
    log->logInfo("Start application...");

    ThreadNet net;
    net.startNet();

    TcpServer server;
    server.startServer();

    return 0;
}
