#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdarg.h>

// 日志级别
typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL
} LogLevel;

// 日志结构体
typedef struct {
    char* message;
    time_t timestamp;
    LogLevel level;
} LogEntry;

// 日志系统初始化
void log_init();

// 正常打印日志
void log_print(LogLevel level, const char* format, ...);

// 过滤打印日志
void log_filter_print(LogLevel level, const char* format, ...);

// 日志系统销毁
void log_destroy();

#endif
