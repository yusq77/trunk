#include <stdio.h>
#include <string.h>

#define debug(format,...) printf("[%s %s %10s@%05d]#  "format"\n",__DATE__, __TIME__,  __func__, __LINE__, ##__VA_ARGS__)

char* _strstr(unsigned long stack_len, char *stack, char *need)
{
  char *res = NULL;
  //printf("need is [%s]\n", need);
  char needle[strlen(need) + 1];
  strcpy(needle, need);
  char *des = strtok(needle, "@");
  debug("%s",des);
  if (!
                  (
                   stack_len >= strlen(des) &&
                   (
                    (res = strstr(stack, des)) ||
                    (res = strstr(stack + stack_len - strlen(des), des))
                   )
                  )
     )
  {
          while((des = strtok(NULL, "@")) != NULL)
          {
                  debug("%s",des);
                  if (
                                  stack_len >= strlen(des) &&
                                  (
                                   (res = strstr(stack, des)) ||
                                   (res = strstr(stack + stack_len - strlen(des), des))
                                  )
                     )
                  {
                          break;
                  }
          }
  }
  return res;
}

int main(int argc, char *argv[])
{
  char *app_data = "yusq@userqq.com|okwe@qq";
  char *server_login_user = "yuq@qq.com@ok"; 

  debug("%s",_strstr(strlen(app_data), app_data, server_login_user));
  return 0;
}
