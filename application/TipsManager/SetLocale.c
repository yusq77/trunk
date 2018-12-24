/*  Copyright (C) 2018 * Ltd. All rights reserved.
#===============================================
#
#      Filename    : SetLocale.c
#
#      Author      : yusq
#      Email       : yusq@qq.com
#      Create date : 2018-08-16 15:06:18
#      Description : ---
#================================================*/

#include <locale.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t curtime;
    struct tm *timer;
    char buffer[80];

    time( &curtime );
    timer = localtime( &curtime );
    strftime(buffer,80,"%c",timer);

    printf("Date is %s\n",buffer);

    printf("Locale is %s\n",setlocale(LC_ALL,"zh_CN"));
    printf("Date is %s\n",buffer);

    return 0; 
}
