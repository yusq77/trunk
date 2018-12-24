/*  Copyright (C) 2018 * Ltd. All rights reserved.
#===============================================
#
#      Filename    : stu.c
#
#      Author      : yusq
#      Email       : yusq@qq.com
#      Create date : 2018-08-16 16:53:56
#      Description : ---
#================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int ID;
    char name[20];

    int math;
    int English;
    int C;
    int average;
}Stu;

int main(int argc, char *argv[])
{
    FILE *fp;
    Stu stu[5];
    int i;
    int average = 0;
    printf("请输入5个同学的信息：学生号，姓名，3门成绩：\n");

    for(i=0;i<5;i++)
    {
        scanf("%d %s %d %d %d",&(stu[i].ID), stu[i].name, &(stu[i].math), &(stu[i].English), &(stu[i].C));
        stu[i].average = (stu[i].math + stu[i].English + stu[i].C) / 3;
    }

    if(!(fp = fopen("./info.txt","w+")))
    {
        printf("cannot open the file\n");
        exit(0);
    }
    for(i=0;i<5;i++)
    {
        fprintf(fp, "%d %s %d %d %d %d\n",stu[i].ID, stu[i].name, stu[i].math, stu[i].English, stu[i].C, stu[i].average);
    }
    fclose(fp);

    return 0;
}
