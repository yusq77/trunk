#include <stdio.h>
#include <ctype.h>

/* int isalpha(int c); 
 * int isalnum(int c);
 */

typedef int (*alpha) (int);

void myprintf( int (*alnum) (int) , const int  ch)
{
  if ( alnum(ch) )
    printf("%c是一个字母或者数字\n",ch);
  else
    printf("%c不是一个字母或者数字\n",ch);

}


int main(int argc, char *argv[])
{
  //输入的值是一个字符才行，整数会报错
  int  ch= '2';
  //判断字母，函数指针
  alpha p = isalpha;
  if ( p(ch) )
    printf("%c是一个字母\n",ch);
  else
    printf("%c不是一个字母\n",ch);

  //判断字母、数字,回调函数
  myprintf( isalnum, ch);

  //判断字符为控制字符
  //直到遇到控制字符停止输出
  int i = 0;
  char str[] = "welecom to iscntrl \n yes";
  while ( !iscntrl(str[i]) )
  {
    putchar(str[i]);
    i++;
  }
  printf("\n");

  return 0;
}
