/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-10-16 15:51:27
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (myArray)[5];//definite array data type, be similar to int a[5] 
typedef int (*myArray_pointer)[5];//definite array pointer data type, like int (*p)[5]

int assignment(int *array, int num)
{
    int i = 0;
    for(i=0; i<num; i++)
        array[i] = i+1;
    return 0;
}

void printArray(int *array, int num)
{
    int i = 0;
    for(i=0; i<num; i++)
        printf("%d\n", array[i]);
}

int main(int argc, char *argv[])
{
    myArray a;
    memset(a, 0, 5);
    assignment(a, 5);
    printArray(a, 5);

    int (*p)[5];//definite array pointer data type
    p = &a;
    printArray((*p), 5);

    myArray_pointer p1;
    p1 = &a;
    printArray((*p1), 5);

    return 0;
}
