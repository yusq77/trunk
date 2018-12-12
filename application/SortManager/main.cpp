/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-11 10:54:00
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "unionlog.h"

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

int main(int argc, char **argv)
{
    UnionLogInit("./Sort.log");
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
    int n = LEN(arr);

    quickSort_3(arr, 0, n-1);
    printArr(arr, n);

    return 0;
}
