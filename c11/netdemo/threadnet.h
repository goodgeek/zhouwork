#ifndef __THREADNET_H__
#define __THREADNET_H__

class ThreadNet
{
public:
    ThreadNet();
    ThreadNet(const ThreadNet&) = delete;
    ThreadNet& operator=(const ThreadNet&) = delete;
    
    void startNet();
private:
};

#endif
