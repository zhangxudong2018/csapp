cmake_minimum_required(VERSION 3.25)

#
# Building in-tree is not allowed (we take care of your craziness).
#
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Prevented in-tree built. Please create a build directory
    outside of the source code and call cmake from there. Thank you.")
endif()

project(
        csapp
        VERSION 1.0.0
        DESCRIPTION "Easy to use, convenient and modern C++ treasure box!"
        #        HOMEPAGE_URL "https://gitee.com/cpp-master/cpp-tbox"
        LANGUAGES C CXX
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message("*")
message("* ${PROJECT_NAME} v${PROJECT_VERSION} (${CMAKE_BUILD_TYPE})")
message("* Copyright (c) 2020-2025 BCST-CSAPP")
message("*")

#
# TESTS
#
option(CMAKE_ENABLE_TEST "Whether to enable unit tests" ON)

option(CSAPP_TEST_TRIE "Whether to enable trie test" ON)

option(CSAPP_TEST_RBT "Whether to enable red-black tree test" ON)

option(CSAPP_TEST_CONVERT "Whether to enable convert test" ON)

option(CSAPP_TEST_INST "Whether to enable instruction test" ON)

option(CSAPP_TEST_RUN_ISA "Whether to enable Instruction Set Architecture(ISA) test" ON)

option(CSAPP_TEST_FORK "Whether to enable fork test" ON)

option(CSAPP_TEST_FORK_COW "Whether to enable fork_cow test" ON)

option(CSAPP_TEST_PAGE_FAULT "Whether to enable page fault test" ON)

option(CSAPP_TEST_CONTEXT "Whether to enable context test" ON)
#
# Compiler args
# -Wall     打开一些必要的警告选项,建议编译时加此选项
# -Werror   视警告为错误,出现任何警告即放弃编译
# -Wextra   打印一下额外的警告信息
# -w        禁止显示所有警告信息
#
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -g -o0 -Wextra -Wno-missing-field-initializers
        -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unused-function)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)