/*
 *system两层含义:
 *1、正确退出后。还需要再判断，操作成功或者操作失败。
 *2、错误退出。
 *
 * 先统一两个说法：
 * （1）system 返回值：指调用system函数后的返回值，比如上例中status为system返回值
 * （2）shell 返回值：指system所调用的shell命令的返回值，比如上例中，test.sh中返回的值为shell返回值。
 */
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/wait.h>  
#include <sys/types.h>  
  
int main()  
{  
    pid_t status;  
  
  
    status = system("./scp.sh");  
  
    if (-1 == status)  
    {  
        printf("system error!");  
    }  
    else  
    {  
        printf("exit status value = [0x%x],systemCommand is success\n", status);  
  
        if (WIFEXITED(status))  //正确退出
        {  
            if (0 == WEXITSTATUS(status)) //操作成功
            {  
                printf("run shell script successfully.\n");  
            }  
            else  //操作失败
            {  
                printf("run shell script fail, script exit code: %d\n", WEXITSTATUS(status));  
            }  
        }  
        else  //错误退出
        {  
            printf("exit status = [%d]\n", WEXITSTATUS(status));  
        }  
    }  
  
    return 0;  
} 
