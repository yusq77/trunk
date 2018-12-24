#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void toCapitals(char *str){
    int i = 0;
    while(str[i]) {
       if(str[i]>'a' && str[i]<'z') 
           //lower_case to capitals
            str[i] -= 32;
            i++;
    }
}


int main(int argc,char *argv[])
{
  int fd; 
  char cmd[512], buf[1024]="hello yusq \n", *filename = argv[1];

  toCapitals(buf);

  if(argc<2)
  {
    printf("./open filename\n");
    exit(1);//<stdlib.h>
  }
  fd=open(filename, O_CREAT | O_RDWR, 0644);
  write(fd,buf,strlen(buf));

  snprintf(cmd, sizeof(cmd), "cat %s",filename);
  system(cmd);

  printf("fd=%d\n",fd);
  
  if(fd>0)
      unlink(filename);
  
  close(fd);     
  return 0;
}

