#include "log.h"

int main()
{
    // 初始化日志系统
    log_init();

    // 正常打印日志
    log_print(LOG_LEVEL_INFO, "This is an info message.");
    log_print(LOG_LEVEL_DEBUG, "This is a debug message.");

    // 测试重复日志
    for (int i = 0; i < 2; i++) {
        log_filter_print(LOG_LEVEL_INFO, "This is a duplicate message.");
        sleep(1); // 模拟时间间隔
    }

    // 测试海量日志
    for (int i = 0; i < 70; i++) {
        log_filter_print(LOG_LEVEL_DEBUG, "This is a flood message.");
        sleep(1); // 模拟时间间隔
    }

    // 销毁日志系统
    log_destroy();

    return 0;
}