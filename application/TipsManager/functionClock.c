/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-20 19:38:14
 *================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fun(int n) {
    while(n--) {
        printf("%d\n",n);
    }
}

int main() {
    int n = 100;
    double theTimes;
    clock_t begin, end;

    begin = clock();
    fun(n);
    printf("hello world!\n");
    end = clock();

    theTimes = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("运行100000L次所需时间：%lf\n", theTimes);


#if 0
    time_t begin, end;
    start = time(NULL);
    /*  执行函数  */
    end = time(NULL);
    printf("时间间隔为 %6.3f\n",difftime(end,start));
#endif
    return 0;

}
