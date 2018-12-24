#include <stdio.h>
#include <string.h>


//  头文件：  #include <string.h>
//  函数说明：strstr()函数用来检索子串在字符串中首次出现的位置，其原型为：char *strstr( char *str, char * substr );
//  参数说明：str为要检索的字符串，substr为要检索的子串。
//  返回值：  返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回NULL。

int main(int argc, char *argv[])
{
    char *p = NULL;
    p = strdup("strdup test");
    printf("p[%s]\n", p);

  char *str = "http://see.xidian.edu.cn/cpp/u/xitong/;token=www.runoob.com/";
  char *substr = "token=";
  char buf[512]; 

  char *s = strstr(str,substr);

  if(s)
  {
    sscanf(s+strlen(substr), "%[^/]", buf);
    printf("截取的字符串s = %s \n", buf);
  }

  return 0;
}
