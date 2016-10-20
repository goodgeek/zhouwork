#include <unistd.h>
#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <time.h>
#include "tcpserver.h"
#include "threadnet.h"
#include "sealbase.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    SealBase base(35, new(int), "zhou");
    SealBase b2;
    b2 = base;

    return 0;
}
