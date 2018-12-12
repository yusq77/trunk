#include "unionlog.h"
#include "color.h"


#if COMPILE_FOR_LIB

#define DEFAULT_LOG_PATH "/var/log/unionlog"
#define DEFAULT_LOG_NAME "default.log"
#define LOG_CONFIG_FILE  "/usr/local/keyou/Config/unionlog.conf"
//#define DEBUG(format,...) printf(L_RED "["__FILE__"]:[%05d]#   "format"\n"NONE, __LINE__, ##__VA_ARGS__)
//#define printf(format, args...) UnionLog(__FILE__, __LINE__, UNION_LOG_DEBUG, "/home/spv/log/AccMananger.log", format, ##args)

static FILE *LogFile = NULL; // ��־�ļ�ָ��
static char AppName[256] = {0}; // ��ǰ������
static LogLevel CurLevel = UNION_LOG_UNKNOWN; // ��ǰ��־����

/*
 * �������ƣ�GetAppName
 * �������ܣ���ȡ��ǰ��������
 * ����˵����
 * ���أ�void
 * �޸���ʷ��
 * 2015-07-28  yusq     ����
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
 * �������ƣ�UnionLogInit
 * �������ܣ���ʼ����־��¼ģ��
 * ����˵����
 *     LogPath   ��־�ļ�����
 * ���أ�void
 * �޸���ʷ��
 * 2015-07-28  yusq ����
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
 * �������ƣ�UnionLogReload
 * �������ܣ����¼�����־��¼ģ������
 * ����˵����
 * ���أ�void
 * �޸���ʷ��
 * 2015-07-28  yusq     ����
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
 * �������ƣ�UnionLog
 * �������ܣ�д��־
 * ����˵����
 *     file     �����־�����ļ�
 *     line     �����־�����к�
 *     level    ��־��Ϣ����
 *     format   ��Ϣ��ʽ���ַ���
 * ���أ�void
 * �޸���ʷ��
 * 2015-07-28  yusq     ����
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
 * �������ƣ�UnionLogEnd
 * �������ܣ���־��¼ģ����β
 * ����˵����
 * ���أ�void
 * �޸���ʷ��
 * 2015-07-28  yusq     ����
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

