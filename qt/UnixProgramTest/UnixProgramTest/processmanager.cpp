#include "processmanager.h"
#include <unistd.h>
#include <sys/types.h>
#include <QDebug>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <QThread>
#include <stdlib.h>
#include <errno.h>
#include <sys/times.h>
#include <signal.h>

ProcessManager::ProcessManager()
{

}

void sig_handler(int sig)
{
    qDebug() << "I get sigaction" << strsignal(sig);
}

void ProcessManager::getIdInfos()
{
    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = sig_handler;
    if (sigaction(SIGALRM, &act, NULL) == -1) {
        qDebug() << QString("sigaction failed") + strerror(errno) << endl;
    }

    sigset_t waitSig;
    sigemptyset(&waitSig);
    sigaddset(&waitSig, SIGALRM);
    if (sigprocmask(SIG_BLOCK, &waitSig, NULL) == -1) {
        qDebug() << QString("sigprocmask failed:") + strerror(errno) << endl;
        return;
    }
}
