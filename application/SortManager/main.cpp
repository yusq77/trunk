/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-11 10:54:00
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "unionlog.h"

#ifdef HAVE_UNUSED
#defined ATTR_UNUSED __attribute__((unused))
#defined UNUSED(x)   do { } while (0)
#else
#define ATTR_UNUSED
#define UNUSED(x)    do { (void)(x); } while (0)
#endif

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

#define check(x)  do { \
    if (!(x)) \
        UnionLogErr("Check failed at "__FILE__":%d in %s(): %s", \
            __LINE__, __func__, #x); \
} while (0)

int main(int argc, char **argv)
{
    UnionLogInit("./Sort.log");
    UnionLogErr("<-- enter main -->");
    int i = 0;
    UNUSED(i);

    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
    int n = LEN(arr);

    quickSort_3(arr, 0, n-1);
    printArr(arr, n);

    return 0;
}
