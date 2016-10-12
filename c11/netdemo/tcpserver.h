#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

class TcpServer
{
public:
    TcpServer();
    ~TcpServer();
    bool startServer();

private:
    bool serverExit_ = false;    
};

#endif
