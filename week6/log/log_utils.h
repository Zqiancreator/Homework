#ifndef LOG_UTILS_H
#define LOG_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// 重复日志检测
int is_duplicate_log(const char* log_message);

// 海量日志屏蔽
int is_flood_log(const char* log_message);

#endif