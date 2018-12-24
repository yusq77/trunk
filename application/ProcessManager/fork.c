/*这是一个调用fork()函数创建子进程的实例,当创建成功之后会分别打印两者对应的进程标志符*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  pid_t pid;        //进程标识符
  pid = fork();     //创建一个新的进程
  printf("fork()返回值为：%d\n",pid);

  if(pid<0)
  {
    printf("创建进程失败!\n");
    exit(1);
  }
  else if(pid==0)   //如果pid为0则表示当前执行的是子进程
    {
      printf("这是子进程,进程标识符是%d\n",getpid());
      int j;
      for(j=0;j<3;j++)
        {
          printf("child: %d\n",j);
          sleep(0);
        }
    }
  else          //否则为父进程
    {
      printf("这是父进程,进程标识符是%d\n",getpid());
      int i;
      for(i=0;i<3;i++)
      {
        printf("parent: %d\n",i);
        sleep(0);
      }
    }

  return 0;
}
