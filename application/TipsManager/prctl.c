/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-11-23 16:17:55
 *================================================*/


#include <stdio.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <unistd.h>

void* pFunc(void *arg)
{
    char name[32];
    prctl(PR_SET_NAME, (unsigned long)"xx");
    prctl(PR_GET_NAME, (unsigned long)name);
    printf("%s\n", name);
    while (1)
        sleep(1);
}

int main(void)
{
    pthread_t tid;
    pthread_create(&tid, NULL, pFunc, NULL);
    pthread_join(tid, NULL);
 
    return 0;
}
