//
// Created by Salmon on 2018/11/2.
//

// 注意这里的用法，参考：https://www.cnblogs.com/liangxiaxu/archive/2012/09/02/2667730.html
extern "C"{
    #include "xinda.h"
}
#include <iostream>

void initialize()
{
    std::cout << "This is called by initialize() method" << std::endl;
    return;
}
