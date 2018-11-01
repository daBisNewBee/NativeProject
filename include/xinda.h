//
// Created by Salmon on 2018/11/2.
//

#ifndef NATIVEPROJECT_XINDA_H
#define NATIVEPROJECT_XINDA_H

/*
 * 错误：
 *  extern "C" void initialize();
 * 报错：
 *  error: expected identifier or '('
 * 原因：
 *  而在C 语言的头文件中，对其外部函数只能指定为extern 类型，C 语言中不支持extern "C" 声明，
 *  在.c 文件中包含了extern "C" 时会出现编译语法错误（error: expected identifier or ‘(’ before string constant ）。
 *
 * */
void initialize();

//class xinda {
//
//};


#endif //NATIVEPROJECT_XINDA_H
