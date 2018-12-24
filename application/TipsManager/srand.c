/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-20 19:20:53
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mySrand(void) {
    int n = 10;
    srand((int)time(NULL));//放在外面,否则调用得到的是相同的数字
    while(n) {
        int m = (rand() % 100) + 1;//rand()%100表示取100以内的随机数，即取了随机数后再对100取余  x=rand()%(Y-X+1)+X 
        printf("m = %d\n",m);
        n--;
    }
}

int main() {
    mySrand();
    return 0;
}
