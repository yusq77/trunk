/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-05 11:31:53
 *================================================*/

#include "unionlog.h"
#include <dirent.h>
#include <malloc.h>


int main()
{
    UnionLogInit("./test.log");
    DIR *dirp;
    struct dirent *dp;

    chdir("./");
    char *s = strdup(getcwd( NULL, 0));
    UnionLogErr("cur pwd= %s", s);
    free(s);
    s = NULL;

    dirp = opendir("."); //打开目录指针
    while ((dp = readdir(dirp)) != NULL)
    { //通过目录指针读目录
        printf("%s\n", dp->d_name );
    }
    (void) closedir(dirp); //关闭目录

    return 0;
}
