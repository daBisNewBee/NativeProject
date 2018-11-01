cmake_minimum_required(VERSION 3.9)
project(NativeProject)

# C Executable
set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 11)
set(LIB_NAME skf)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

# 相当于g++选项中的-I参数的作用
include_directories(${PROJECT_SOURCE_DIR}/output/include)

# 相当于g++命令的-L选项的作用, 也相当于环境变量中增加LD_LIBRARY_PATH的路径的作用
link_directories(${PROJECT_SOURCE_DIR}/output)

# /Users/user/CLionProjects/NativeProject
MESSAGE(STATUS "this is PROJECT_SOURCE_DIR:" ${PROJECT_SOURCE_DIR})

# /Users/user/CLionProjects/NativeProject/cmake-build-debug
MESSAGE(STATUS "this is PROJECT_BINARY_DIR:" ${PROJECT_BINARY_DIR})

add_executable(NativeProject main.c)

target_link_libraries(NativeProject skf)

add_subdirectory(lib)