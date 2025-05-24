#include "gtest/gtest.h"
#include <cstdio>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
extern "C" {
#include "../src/log.h" // 调整路径以匹配您的项目结构
#include "../src/log_utils.h"
}
// 测试辅助函数：清空日志文件
void clear_log_file()
{
    std::ofstream log_file("app.log", std::ios::out | std::ios::trunc);
    log_file.close();
}

// 测试辅助函数：读取日志文件内容
std::string read_log_file()
{
    std::ifstream log_file("app.log");
    std::string content((std::istreambuf_iterator<char>(log_file)),
                        std::istreambuf_iterator<char>());
    return content;
}

// 测试套件初始化
class LogTestEnvironment : public ::testing::Environment
{
public:
    virtual void SetUp()
    {
        log_init();
        clear_log_file();
    }

    virtual void TearDown()
    {
        log_destroy();
        clear_log_file();
    }
};

// 注册测试环境
LogTestEnvironment *const log_test_env =
    static_cast<LogTestEnvironment *>(::testing::AddGlobalTestEnvironment(new LogTestEnvironment()));

// 测试日志打印功能
TEST(LogTest, BasicLogging)
{
    // 打印不同级别的日志
    log_print(LOG_LEVEL_INFO, "Test info message");
    log_print(LOG_LEVEL_DEBUG, "Test debug message");
    log_print(LOG_LEVEL_WARNING, "Test warning message");
    log_print(LOG_LEVEL_ERROR, "Test error message");
    log_print(LOG_LEVEL_CRITICAL, "Test critical message");

    std::string log_content = read_log_file();

    // 验证日志内容
    EXPECT_NE(log_content.find("Test info message"), std::string::npos);
    EXPECT_NE(log_content.find("Test debug message"), std::string::npos);
    EXPECT_NE(log_content.find("Test warning message"), std::string::npos);
    EXPECT_NE(log_content.find("Test error message"), std::string::npos);
    EXPECT_NE(log_content.find("Test critical message"), std::string::npos);
}

// 测试重复日志检测
TEST(LogTest, DuplicateLogFiltering)
{
    // 第一次打印日志
    log_filter_print(LOG_LEVEL_INFO, "Duplicate test message");

    // 短暂等待后再次打印相同日志
    std::this_thread::sleep_for(std::chrono::seconds(1));
    log_filter_print(LOG_LEVEL_INFO, "Duplicate test message");

    std::string log_content = read_log_file();

    // 验证只打印了一次日志
    size_t first_occurrence = log_content.find("Duplicate test message");
    size_t second_occurrence = log_content.find("Duplicate test message", first_occurrence + 1);
    EXPECT_EQ(second_occurrence, std::string::npos);
}

// 测试海量日志屏蔽
TEST(LogTest, FloodLogFiltering)
{
    // 打印超过阈值的相同日志
    for (int i = 0; i < 70; i++) {
        log_filter_print(LOG_LEVEL_DEBUG, "Flood test message");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::string log_content = read_log_file();

    // 验证日志数量不超过阈值
    int count = 0;
    size_t pos = 0;
    while ((pos = log_content.find("Flood test message", pos)) != std::string::npos) {
        count++;
        pos += strlen("Flood test message");
    }
    EXPECT_LT(count, 70);
}

// 测试多线程日志打印
TEST(LogTest, MultiThreadLogging)
{
    std::vector<std::thread> threads;

    // 启动多个线程打印日志
    for (int i = 0; i < 5; i++) {
        threads.emplace_back([i]() {
            for (int j = 0; j < 10; j++) {
                log_print(LOG_LEVEL_INFO, "Thread %d message %d", i, j);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        });
    }

    // 等待所有线程完成
    for (auto &thread : threads) {
        thread.join();
    }

    std::string log_content = read_log_file();

    // 验证所有线程的日志都被正确记录
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            std::string expected = std::string("Thread ") + std::to_string(i) +
                                   " message " + std::to_string(j);
            EXPECT_NE(log_content.find(expected), std::string::npos);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
