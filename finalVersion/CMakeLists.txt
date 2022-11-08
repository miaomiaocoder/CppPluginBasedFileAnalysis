# $ cmake --version
cmake_minimum_required(VERSION 3.0)

# SET(CMAKE_C_COMPILER /usr/bin/gcc)
# SET(CMAKE_CXX_COMPILER /usr/bin/g++)
SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

# Set the project name
project(version3)

# 设置debug模式，如果没有这一行将不能调试设断点
# set (CMAKE_BUILD_TYPE "Debug") 

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugin)
# 生成库，动态库是SHARED，静态库是STATIC
add_library(line SHARED Line.cpp)
add_library(word SHARED Word.cpp) 
add_library(size SHARED Size.cpp)
add_library(suffixl SHARED SuffixL.cpp)
add_library(suffixs SHARED SuffixS.cpp) 
add_library(suffixw SHARED SuffixW.cpp)   

# Add an executable
add_executable(main main.cpp SearchPlugin.cpp CPluginController.cpp)
TARGET_LINK_LIBRARIES(main dl)