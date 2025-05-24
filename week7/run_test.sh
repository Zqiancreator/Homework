#!/bin/bash

# 项目根目录
PROJECT_DIR=$(dirname "$0")

# 构建目录
BUILD_DIR="${PROJECT_DIR}/build"

# 创建构建目录
mkdir -p "${BUILD_DIR}"

# 进入构建目录
cd "${BUILD_DIR}"

# 运行 CMake 配置
cmake ../test

# 构建项目
make

# 运行测试
./log_test