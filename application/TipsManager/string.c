#include<stdio.h>
#include<string.h>

int main()
{
  char a[16];
  memset(a,0,sizeof(a));

  memcpy(a,"yusq",sizeof(a));

  
  printf("%d \n",strcmp(a,"yusq"));
  return 0;
}
