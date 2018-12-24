//#include <memcpy.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <config.h>
#include <stddef.h>
#include <string.h>

//typedef unsigned int size_t;

int
strcspn_yusq(const char *s, const char *reject)
{
  int count = 0;

  while (*s != '\0')
    if (strchr (reject, *s++) == NULL)
    {
      ++count;
      printf("count = %d *s=%c\n", count, *s);
    }
    else
      return count;

  return count;
}

int main()
{
      char *u = strdup("https://www.baidu.com/s?ie=utf-8&tn=02003390_8_hao_pg&wd=vim%20%E5");

/*
      for (int i; u[i = strcspn(u, "\\\"'`${};() \r\n\t\v\f")]; ) {
        static const char hex[] = "0123456789ABCDEF";
        u = realloc(u, strlen(u) + 4);
        printf("u = %s\n", u);
        memmove(u + i + 3, u + i + 1, strlen(u + i));
        u[i + 2]           = hex[ u[i]       & 0xF];
        u[i + 1]           = hex[(u[i] >> 4) & 0xF];
        u[i]               = '%';
        printf("u1= %s\n", u);
      }
      */
    int i = strcspn_yusq(u, "\\\"'`${};() \r\n\t\v\f");
    printf("i = %d\n", i);

    return 0;
}
