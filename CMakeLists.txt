cmake_minimum_required(VERSION 3.9)
project(NativeProject)

# C Executable
#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 11)
set(LIB_NAME skf)

# LIBRARY_OUTPUT_PATH是cmake默认变量，修改它可以把库文件的路径修改，本例子中修改为./output
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

# #设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/bin)

# 相当于g++选项中的-I参数的作用
include_directories(${PROJECT_SOURCE_DIR}/include)

# 相当于g++命令的-L选项的作用, 也相当于环境变量中增加LD_LIBRARY_PATH的路径的作用
link_directories(${PROJECT_SOURCE_DIR}/output)

# /Users/user/CLionProjects/NativeProject
MESSAGE(STATUS "this is PROJECT_SOURCE_DIR:" ${PROJECT_SOURCE_DIR})

# /Users/user/CLionProjects/NativeProject/cmake-build-debug
MESSAGE(STATUS "this is PROJECT_BINARY_DIR:" ${PROJECT_BINARY_DIR})

add_executable(NativeProject main.c cpp/xinda.cpp cpp/basic.cpp include)

target_link_libraries(NativeProject skf)

add_subdirectory(lib)

add_executable(my_test test/my_test.c)
#target_link_libraries(my_test ${PROJECT_NAME} pthread)