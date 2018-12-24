/*这是一个调用fork()函数创建一个子进程,然后分别打印输出子进程和父进程中的变量的实例*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int glob = 6;
int main(int argc,char *argv[])
{
  int var;    //内部变量
  pid_t pid;      //文件标识符
  var = 88;   //内部变量赋值
  printf("创建新进程之前.\n");   //还没有创建子进程
  if((pid=fork())<0)
  {
    perror("创建子进程失败!\n");
  }
  else if(pid==0)
  {
    glob++;
    var++;
    printf("子进程标识符：%d\n",getpid());
  }
  else
  {
    sleep(2); //父进程阻塞两秒
    printf("父进程标识符：%d\n",getpid());
  }

  printf("进程标识符为=%d,glob=%d,var=%d\n",getpid(),glob,var);//分别在子进程中输出两个变量的值
  exit(0);
}
