/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-18 11:01:07
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <malloc.h>
#include "tips.h"

/* Test Function Type */
/**** Test Template ******/
typedef void(*TESTFUNC)(void);
static int iscontinue = 1;

#define TEST_CYCLE(c, f, s) \
{ \
    c = 0; \
    while(iscontinue) \
    { \
        f = s[c++]; \
        if(f == NULL) break; \
        f(); \
    } \
}

void setLocaleTest()
{
    setLocale();
}


TESTFUNC TestFunc_C4[] =
{
    setLocaleTest,
    NULL
};

//Test bak
TESTFUNC TestFunc_X[] =
{
    NULL
};

int main(int argc, char *argv[])
{
    int cnt = 0;
    iscontinue = 1;
    TESTFUNC pFunc = NULL;

    TEST_CYCLE(cnt, pFunc,TestFunc_C4)

    return 0;
}
