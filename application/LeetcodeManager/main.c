/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-18 11:01:07
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "leetcode.h"

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

void subStrCountTest()
{
    printf("subStrCount(%s, %s) = %d\n", "dh123dhgfdgsshdhscnbdh", "dh", subStrCount("dh123dhgfdgsshdhscnbdh","dh"));
}

void reverseTest()
{
    int x = 49;
    printf("reverse(%d) is %d\n",x, reverse(x));
}

void LongestCommonPrefixTest()
{
    const char *strs[]={ "flower","flow","flight"};
    char *des = (char *)malloc(24);

    longestCommonPrefix(des, strs, 3);

    printf("flower,flow,flight: longestCommonPrefix of strs is %s\n", des);
    free(des);

}

void isPalindromeTest()
{
    int x = 77;
    /* while((scanf("%d",&x)) != EOF) */
    if(0 == isPalindrome(x))
        printf("%d is not a palindrome.\n",x);
    else
        printf("%d is a palindrome.\n",x);

}


TESTFUNC TestFunc_C4[] =
{
    subStrCountTest,
    reverseTest,
    LongestCommonPrefixTest,
    isPalindromeTest,
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
