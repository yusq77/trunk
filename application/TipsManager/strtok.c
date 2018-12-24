/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-09-03 07:07:05
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "my name is yusq";
    char *token = NULL;

    /* 分隔函数strtok, 注意：使用strtok处理过的字符串会被更改 */
    token = strtok(str, " ");
    while(token) {
        printf("token = %s\n", token);
        token = strtok(NULL, " ");
    }
    printf("str = %s\n", str);

    return 0;
}
