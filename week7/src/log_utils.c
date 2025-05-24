#include "log_utils.h"
#include "log.h"

// 重复日志检测
int is_duplicate_log(const char *log_message)
{
    static char last_log_message[1024] = {0};
    static time_t last_log_time = 0;

    // 检查是否为重复日志
    if (strcmp(log_message, last_log_message) == 0) {
        // 检查是否在一小时内
        time_t now = time(NULL);
        if (difftime(now, last_log_time) < 3600) {
            return 1; // 重复日志，不打印
        }
    }

    // 更新日志信息
    strcpy(last_log_message, log_message);
    last_log_time = time(NULL);

    return 0;
}

// 海量日志屏蔽
int is_flood_log(const char *log_message)
{
    static char flood_log_message[1024] = {0};
    static int flood_log_count = 0;
    static time_t flood_log_start_time = 0;

    // 检查是否为海量日志
    if (strcmp(log_message, flood_log_message) == 0) {
        // 检查是否在一分钟内
        time_t now = time(NULL);
        if (difftime(now, flood_log_start_time) < 60) {
            flood_log_count++;
            if (flood_log_count >= 60) {
                return 1; // 海量日志，屏蔽
            }
        } else {
            // 重置计数器
            flood_log_start_time = now;
            flood_log_count = 1;
        }
    } else {
        // 更新日志信息
        strcpy(flood_log_message, log_message);
        flood_log_start_time = time(NULL);
        flood_log_count = 1;
    }

    return 0;
}