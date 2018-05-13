#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"

#include <ctime>
#include <cstdio>
#include <cstring>

char* printTime() {
	static char ret[1024];
	strcpy(ret, "");
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	sprintf(ret, "[%02d:%02d:%02d]", p->tm_hour, p->tm_min, p->tm_sec);
	return ret;
}

char* getLogfileName() {
	static char ret[1024];
	static bool reg = false;
	if (reg)
		return ret;
	reg = true;
	strcpy(ret, "");
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	sprintf(ret, "./log/%04d%02d%02d-%02d%02d%02d.log", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	return ret;
}
