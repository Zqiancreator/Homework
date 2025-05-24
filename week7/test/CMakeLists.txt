cmake_minimum_required(VERSION 3.10)
project(LogTest)

# 添加Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加被测试的源代码
add_library(log_lib ../src/log.c ../src/log_utils.c)

# 添加测试程序
add_executable(log_test log_test.cpp)
target_link_libraries(log_test log_lib gtest gtest_main pthread)

# 配置测试运行
enable_testing()
add_test(NAME log_test COMMAND log_test)
