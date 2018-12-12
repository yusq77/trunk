#ifndef UNION_LOG_H
#define UNION_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	UNION_LOG_UNKNOWN,
	UNION_LOG_DEBUG,
	UNION_LOG_INFO,
	UNION_LOG_ERROR,
	UNION_LOG_FATAL,
	UNION_LOG_MAX
}LogLevel;

#define UnionLogDebug(format, args...) UnionLog(__FILE__, __LINE__, UNION_LOG_DEBUG, format, ##args)
#define UnionLogInfo(format, args...)  UnionLog(__FILE__, __LINE__, UNION_LOG_INFO, format, ##args)
#define UnionLogErr(format, args...)   UnionLog(__FILE__, __LINE__, UNION_LOG_ERROR, format, ##args)
#define UnionLogFatal(format, args...) UnionLog(__FILE__, __LINE__, UNION_LOG_FATAL, format, ##args)

void UnionLogInit(const char *LogPath);
void UnionLogReload(void);
void UnionLog(const char *file, int line, LogLevel level, const char *format, ...);
void UnionLogEnd(void);

#ifdef __cplusplus
}
#endif

#endif
