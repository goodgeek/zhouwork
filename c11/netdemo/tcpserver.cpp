#include "tcpserver.h"
#include <sys/types.h>
#include <sys/socket.h>
#include "logger.h"
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

TcpServer::TcpServer()
{
}

TcpServer::~TcpServer()
{
}

bool TcpServer::startServer()
{
    Logger log;
    log.logInfo("Start Tcp Server on 8003");
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        return false;     
    }
    
    struct sockaddr_in serverAddr;
    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(8003);
    if (bind(listenfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        return false;
    }
    log.logInfo("Bind address success");

    if (listen(listenfd, 10) == -1) {
        return false;
    }
    log.logInfo("Listen success");

    struct sockaddr_in clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    while (!serverExit_) {
        int clientfd = accept(listenfd, (struct sockaddr*)&clientAddr, &addrLen);
        
        log.logInfo("Hava client");
        char buf[1024];
        ssize_t nr = recv(clientfd, buf, sizeof(buf), 0);
        buf[nr] = '\0';

        
        close(clientfd);
    }
    
    close(listenfd);
}
