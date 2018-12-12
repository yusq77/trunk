#include "unionlog.h"
#include "color.h"


#if COMPILE_FOR_LIB

#define DEFAULT_LOG_PATH "/var/log/unionlog"
#define DEFAULT_LOG_NAME "default.log"
#define LOG_CONFIG_FILE  "/usr/local/keyou/Config/unionlog.conf"
//#define DEBUG(format,...) printf(L_RED "["__FILE__"]:[%05d]#   "format"\n"NONE, __LINE__, ##__VA_ARGS__)
//#define printf(format, args...) UnionLog(__FILE__, __LINE__, UNION_LOG_DEBUG, "/home/spv/log/AccMananger.log", format, ##args)

static FILE *LogFile = NULL; // 日志文件指针
static char AppName[256] = {0}; // 当前进程名
static LogLevel CurLevel = UNION_LOG_UNKNOWN; // 当前日志级别

/*
 * 函数名称：GetAppName
 * 函数功能：获取当前进程名称
 * 参数说明：
 * 返回：void
 * 修改历史：
 * 2015-07-28  yusq     创建
 */
static void GetAppName(void)
{
	char path[256], *sep;

	sprintf(path, "/proc/%d/exe", getpid());
	readlink(path, AppName, sizeof(AppName));
	sep = strrchr(AppName, '/');
	if (NULL != sep)
		memmove(AppName, sep + 1, strlen(sep));
}

/*
 * 函数名称：UnionLogInit
 * 函数功能：初始化日志记录模块
 * 参数说明：
 *     LogPath   日志文件名称
 * 返回：void
 * 修改历史：
 * 2015-07-28  yusq 创建
 */
void UnionLogInit(const char *LogPath)
{
	char *sep, path[256] = {0};

	mkdir(DEFAULT_LOG_PATH, 0777);

	if (NULL == LogPath)
		sprintf(path, "%s/%s", DEFAULT_LOG_PATH, DEFAULT_LOG_NAME);
	else if (NULL == (sep = strrchr(LogPath, '/')))
		sprintf(path, "%s/%s", DEFAULT_LOG_PATH, LogPath);
	else
		strcpy(path, LogPath);

	if (NULL != LogFile)
		fclose(LogFile);
	LogFile = fopen(path, "a");

	GetAppName();
	UnionLogReload();
}

/*
 * 函数名称：UnionLogReload
 * 函数功能：重新加载日志记录模块配置
 * 参数说明：
 * 返回：void
 * 修改历史：
 * 2015-07-28  yusq     创建
 */
void UnionLogReload(void)
{
	FILE *fp;

	fp = fopen(LOG_CONFIG_FILE, "r");
	if (NULL == fp)
	{
		fp = fopen(LOG_CONFIG_FILE, "a");
		if (NULL != fp)
		{
			fprintf(fp, "%d", UNION_LOG_ERROR);
			fclose(fp);
		}
		CurLevel = UNION_LOG_ERROR;
		return;
	}
	fscanf(fp, "%d", (int*)&CurLevel);
	fclose(fp);

	if (CurLevel <= UNION_LOG_UNKNOWN || CurLevel >= UNION_LOG_MAX)
		CurLevel = UNION_LOG_ERROR;
}

/*
 * 函数名称：UnionLog
 * 函数功能：写日志
 * 参数说明：
 *     file     输出日志所在文件
 *     line     输出日志所在行号
 *     level    日志消息级别
 *     format   消息格式化字符串
 * 返回：void
 * 修改历史：
 * 2015-07-28  yusq     创建
 */
void UnionLog(const char *file, int line, LogLevel level, const char *format, ...)
{
	va_list ap;
	time_t timep;
	struct tm *p;

	if (NULL == LogFile)
		UnionLogInit(NULL);
	if (NULL == LogFile || level < CurLevel) return;

	time(&timep);
	p = localtime(&timep);
	fprintf(LogFile, "%02d-%02d-%02d %02d:%02d:%02d %s:%s:%d $ ",
		p->tm_year - 100, p->tm_mon + 1, p->tm_mday,
		p->tm_hour, p->tm_min, p->tm_sec,
		AppName, file, line);

	va_start(ap, format);
	vfprintf(LogFile, format, ap);
	fprintf(LogFile, "\n");
	fflush(LogFile);
	va_end(ap);
}

/*
 * 函数名称：UnionLogEnd
 * 函数功能：日志记录模块收尾
 * 参数说明：
 * 返回：void
 * 修改历史：
 * 2015-07-28  yusq     创建
 */
void UnionLogEnd(void)
{
	if (NULL != LogFile)
		fclose(LogFile);
	LogFile = NULL;
}

//#ifndef COMPILE_FOR_LIB
#else
int main()
{
	char *msg= "SPV User for test display";
	UnionLogFatal("%s", msg);
	return 0;
}
#endif

