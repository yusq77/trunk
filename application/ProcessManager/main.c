/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-12 19:05:47
 *================================================*/

/*
 *进程双向通信
 */
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

#define check(x)  do { \
    if (!(x)) \
        printf("Check failed at "__FILE__":%d in %s(): %s", \
            __LINE__, __func__, #x); \
} while (0)

int main()
{
    int sv[2];    // noname socketfd
    ssize_t _s;
    char buf[1024];

    //checkd(socketpair(PF_LOCAL,SOCK_STREAM,0,sv)); //succ:0 fail:-1
    check(!socketpair(AF_UNIX, SOCK_STREAM, 0, sv)); //succ: 0  fail: -1

    switch(fork())
    {
        case 0:
        {
            //close(sv[0]); //close read
            close(sv[1]); //close read

            const char* msg_kid = "I am a kid.\n";
            for(; ;)
            {
               // write(sv[1],msg,strlen(msg));
                write(sv[0],msg_kid,strlen(msg_kid));
                sleep(1);

                //ssize_t _s = read(sv[1],buf,sizeof(buf)-1);
                _s = read(sv[0],buf,sizeof(buf)-1);
                if(_s > 0)
                {
                    buf[_s] = '\0';
                    printf("Kid: %s\n",buf);
                }
            }

        }
        case -1:
        {
            printf("[server] Launcher fork() failed!");
            break;
        }
        default:
        {
            //close(sv[1]);//close write
            close(sv[0]);//close write
            const char* msg_dad = "I am a dad.\n";
            for(; ;)
            {
                //ssize_t _s = read(sv[0],buf,sizeof(buf)-1);
                _s = read(sv[1],buf,sizeof(buf)-1);
                if(_s > 0)
                {
                    buf[_s] = '\0';
                    printf("Dad: %s\n",buf);
                    sleep(1);
                }
               // write(sv[0],msg,strlen(msg));
                write(sv[1],msg_dad,strlen(msg_dad));
            }

        }
    }
    return 0;
}
