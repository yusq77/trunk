/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-10-15 10:45:38
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* stack order */
void xprintf(int a)
{
    printf("%d %d %d %d %d %d\n",a--, --a, a--, --a, a--, --a );  
}

void sort(int a[], int num)
{
    //array degenerate into pointers
    //the bytes in the 64 bit compiler are 8
    num = sizeof(a)/sizeof(a[0]);
    printf("num = %d\n", num);
}

/* one-level pointer*/
char *getMem1(int num)
{
    //allocate memory
    char *p1 = NULL;
    p1 = (char *)malloc(sizeof(char) * num);
    if (p1 == NULL)
    {
        return NULL;
    }

    return p1;
    
}
/* one-level pointer*/
void getMem1_free(char *p1)
{
    //free memory
    if(p1 != NULL)
    {
        free(p1);
        p1 = NULL;
    }
}
/*one-level pointer printf*/
void printPointer1(char *p1)
{
    printf("%s\n", p1);
}

/* two-levelpointer allocate memory*/
char **getMem2(int num)
{
    char **p2 = NULL;
    p2 = (char **)malloc(sizeof(char *) * num);
    if(p2 == NULL)
    {
        return NULL;
    }
    int i = 0;
    for(i = 0; i<num; i++)
    {
        p2[i] = (char *)malloc(sizeof(char) * 100);
        sprintf(p2[i], "%d%d%d", i, i, i);
    }
    return p2;
}
/* two-level pointer :
 * Function parameters allocate memory for two level pointer, indirect assignment, recovery memory
 */
int getMem2_1(char ***p3, int num)
{
    if(p3 == NULL)
    {
        return -1;
    }
    char **p2 = NULL;
    p2 = (char **)malloc(sizeof(char *) * num);
    if(p2 == NULL)
    {
        return -1;
    }
    int i = 0;
    for(i=0; i<num; i++)
    {
        p2[i] = (char *)malloc(sizeof(char) * 10);
        sprintf(p2[i], "%d%d%d", i, i, i);
    }
    *p3 = p2;
    return 0;
}

/* two-level pointer free*/
void getMem2_free(char **p2, int num)
{
    int i = 0;
    for(i=0; i<num; i++)
    {
        if(p2[i] != NULL)
        {
            free(p2[i]);
            p2[i] = NULL;
        }
    }
    if(p2 != NULL)
    {
        free(p2);
        p2 = NULL;
    }

}
/* two-level pointer printf */
void printPointer2(char **p2, int num)
{
    int i = 0;
    for(i=0; i<num; i++)
    {
        printf("%s\n", p2[i]);
    }
}


int main(int argc, char *argv[])
{
    char **p = NULL;
    //p = getMem2(10);
    getMem2_1(&p, 10);
    printPointer2(p, 10);
    getMem2_free(p, 10);

#if 0
    char buf[512] = "of";
    printf("buf_len = %d strlen(buf) = %d strlen(of) = %d \n", sizeof(buf)/sizeof(buf[0]), strlen(buf), strlen("of"));
#endif

    return 0;
}
