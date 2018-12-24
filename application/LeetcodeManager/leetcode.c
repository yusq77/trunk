/*  Copyright (C) 2018 * Ltd. All rights reserved.
#===============================================
#
#      Filename    : isPalindrome.c
#
#      Author      : yusq
#      Email       : yusq@qq.com
#      Create date : 2018-08-16 19:51:07
#      Description : ---
#================================================*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "leetcode.h"
/*
typedef enum {
    false,
    true
} bool;
*/

int  isPalindrome(int x ) {
    int tmp = x, y = 0;
    if(x<0)
        return -1;
    while(x) {
        y = y*10 + x%10;
        x /= 10;
    }
    if(y == tmp)
        return 0;
    else
        return -1;
}
/*
bool isPalindrome(int x) {
    int left, right, len = 1;
    while(x/len >= 10) {
        len *= 10;
    }
    while(x) {
        left = x/len;
        right = x%10;
        if(left != right) return false;
        x = (x % len) / 10;
        len /= 100;
    }
    return true;
}
*/

/*
bool isPalindrome(int x) {

   //negative number
   if(x < 0)
       return false;

   int len = 1;
    while(x / len >= 10)
        len *= 10;

    while(x > 0)    {

        //get the head and tail number
        int left = x / len;
        int right = x % 10;

        if(left != right)
            return false;
        else    {
            //remove the head and tail number
            x = (x % len) / 10;
            len /= 100;
        }
    }

    return true;
}
*/


char *longestCommonPrefix(char *des, const char **strs, int strsSize)
{
    int i, j;

    if(strsSize <= 0) {
        return "";
    }
    strcpy(des, strs[0]);
    for(i=1;i<strsSize;i++)
    {
        j = 0;
        while(des[j] && strs[i][j] && (des[j] == strs[i][j])) {
            j++;
        }
        des[j] = '\0';
    }
    return des;
}


/*
int reverse(int x) {
    long long res = 0;
    while(x) {
        res = 10*res + x%10;
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}
*/
int reverse(int x)
{
    int res = 0, t = 0;
    while(x) {
        t = res*10 + x%10;
        if(t/10 != res) return 0;
        res = t;
        x /= 10;
    }
    return res;
}


int subStrCount(char *str, char *substr)
{
    if(!str && !substr) {
        printf("please entry again!\n");
    }
    int count = 0, len = strlen(substr);
    char *p;
    while((p = strstr(str, substr)))
    {
        count++;
        str = p + len;
    }
    return count;
}
