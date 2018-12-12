#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unionerrinfo.h"

/*
 * 函数名称：UnionGetErrMsg
 * 函数功能：根据提供的错误码获取错误信息
 * 参数说明：
 *   ErrNo     错误码
 * 返 回 值：
 *   NULL      没有指定的错误码
 *   ErrMsg    错误信息
 * 修改历史：
 *   修改日期     修改人     修改内容
 *   2015-12-12   gongf      创建
 */
const char *UnionGetErrMsg(int ErrNo)
{
    int i = 0;

    for (i = 0; i < sizeof(SKVErrInfo) / sizeof(SKVErrInfo[0]); i++)
    {
        if (SKVErrInfo[i].ErrNo == ErrNo)
        {
            return SKVErrInfo[i].ErrMsg;
        }
    }

    return NULL;
}

/* 函数名称：UnionGetErrDetail
 * 函数功能：根据提供的错误码获取错误详细信息
 * 参数说明：
 *   ErrNo     错误码
 * 返 回 值：
 *   NULL             没有指定的错误码
 *   ErrDetailInfo    错误详细信息
 * 修改历史：
 *   修改日期     修改人     修改内容
 *   2015-12-12   gongf      创建
 */
const char *UnionGetErrDetail(int ErrNo)
{
    int i = 0;

    for (i = 0; i < sizeof(SKVErrInfo) / sizeof(SKVErrInfo[0]); i++)
    {
        if (SKVErrInfo[i].ErrNo == ErrNo)
        {
            return SKVErrInfo[i].ErrDetailInfo;
        }
    }

    return NULL;
}

