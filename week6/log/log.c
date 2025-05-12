#include "log.h"
#include "log_utils.h"

// 日志文件指针
FILE *log_file = NULL;

// 日志缓冲区
char log_buffer[1024];

// 日志锁
pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

// 日志级别映射
const char *log_level_strings[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
    "CRITICAL"};

// 日志系统初始化
void log_init()
{
    // 打开日志文件
    log_file = fopen("app.log", "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
}

// 正常打印日志
void log_print(LogLevel level, const char *format, ...)
{
    pthread_mutex_lock(&log_mutex);

    // 获取当前时间
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    // 格式化日志消息
    va_list args;
    va_start(args, format);
    vsnprintf(log_buffer, sizeof(log_buffer), format, args);
    va_end(args);

    if (is_flood_log(log_buffer)) {
        pthread_mutex_unlock(&log_mutex);
        return; // 如果是海量日志，直接返回，不打印
    }
    // 打印日志到控制台
    fprintf(stderr, "[%s] %s %s:%d: %s\n", log_level_strings[level], asctime(timeinfo), __FILE__, __LINE__, log_buffer);

    // 写入日志文件
    fprintf(log_file, "[%s] %s %s:%d: %s\n", log_level_strings[level], asctime(timeinfo), __FILE__, __LINE__, log_buffer);
    fflush(log_file);

    pthread_mutex_unlock(&log_mutex);
}

// 过滤打印日志
void log_filter_print(LogLevel level, const char *format, ...)
{
    pthread_mutex_lock(&log_mutex);

    // 获取当前时间
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    // 格式化日志消息
    va_list args;
    va_start(args, format);
    vsnprintf(log_buffer, sizeof(log_buffer), format, args);
    va_end(args);

    if (is_flood_log(log_buffer)) {
        pthread_mutex_unlock(&log_mutex);
        return; // 如果是海量日志，直接返回，不打印
    }
    // 判断是否为重复日志
    if (is_duplicate_log(log_buffer)) {
        pthread_mutex_unlock(&log_mutex);
        return;
    }

    // 打印日志到控制台
    fprintf(stderr, "[%s] %s %s:%d: %s\n", log_level_strings[level], asctime(timeinfo), __FILE__, __LINE__, log_buffer);

    // 写入日志文件
    fprintf(log_file, "[%s] %s %s:%d: %s\n", log_level_strings[level], asctime(timeinfo), __FILE__, __LINE__, log_buffer);
    fflush(log_file);

    pthread_mutex_unlock(&log_mutex);
}

// 日志系统销毁
void log_destroy()
{
    if (log_file != NULL) {
        fclose(log_file);
    }
}