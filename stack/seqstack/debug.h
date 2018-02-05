#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define ERRBUFLEN 1024
#define SYS_ERR_ON //系统错误打印开关
#define CUSTOM_ERR_ON //自定义错误打印开关
#define INFO_ON //调试信息打印开关（正式版本注释掉即可）


#ifdef SYS_ERR_ON
	#define DEBUG_SYSERR(str) \
		do \
		{ \
		char errbuf[ERRBUFLEN] = {'\0'}; \
		snprintf(errbuf, ERRBUFLEN, "\n[file: %s func: %s() line: %d] %s",__FILE__, __func__, __LINE__, str); \
		perror(errbuf); \
		} while (0)
#else
	#define DEBUG_SYSERR(str)
#endif


#ifdef CUSTOM_ERR_ON
	#define DEBUG_CUSTOMERR(str) \
		do \
		{ \
		printf("\n[file: %s func: %s() line: %d] %s \n\n", __FILE__, __func__, __LINE__, str); \
		} while(0)
#else
	#define DEBUG_CUSTOMERR(str)
#endif


#ifdef INFO_ON
	#define DEBUG_INFO(fmt,args...) \
		do \
		{ \
		printf("\n[file: %s func: %s() line: %d] "#fmt" \n\n", __FILE__, __func__, __LINE__, ##args); \
		} while(0)
#else
	#define DEBUG_INFO(fmt,args...)
#endif

#endif

