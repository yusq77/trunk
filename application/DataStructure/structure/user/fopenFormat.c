#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_LEN 512

typedef struct User{
  char username[65];
  char email[65];
  char phone[65];
}User;


int main(int argc,char *argv[])
{
  User user[MAX_LEN];
  int i = 0;
  FILE *fp = NULL;
  fp = fopen("info.txt","r");
  if (fp == NULL)
    printf("cannot open the file !\n ");

  for(i=0;!feof(fp)&&i<MAX_LEN;i++)
  {
    fscanf(fp,"%[^,],%[^,],%s\n",user[i].username,user[i].email,user[i].phone);
  }

  fclose(fp);
  fp = NULL;

  int j = 0;
  for(j=1;j<i;j++)
  {
    printf("%s %s %s\n",user[j].username,user[j].email,user[j].phone);
  }

  return 0;
}
