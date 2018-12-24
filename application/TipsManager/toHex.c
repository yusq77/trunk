#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[33];

//系统函数
//本系统不支持
//第一种
/*
char *inttohex(int num)
{
  itoa(num,buf,16);
  return buf;
}
*/

//系统函数
//第二种
void inttohex_sprintf(char *desHex, int num)
{
  sprintf(desHex,"%x",num);
//  return desHex;
}

int main(int argc, char *argv[])
{
    char desHex[64];
    inttohex_sprintf(desHex, 60);
    printf("%s\n",desHex);

    return 0;
}
