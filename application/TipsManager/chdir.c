/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-11-26 11:28:08
 *================================================*/

#include <unistd.h> 
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    chdir("/tmp"); 
    char *s = strdup(getcwd( NULL, 0));
    printf("current pwd: %s \n",getcwd(NULL,0));

    if(s != NULL) 
    {
        free(s);
        s = NULL;
    }
    return 0;
} 
