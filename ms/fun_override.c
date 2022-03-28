//
// Created by Salmon on 2022/3/28.
//

/**
 *
 *  函数重载的原理
 *
 *  为什么C++支援函数重载，而C语言不可以了？
 *
 *  原因：
 *      c编译器 和 c++编译器对函数名的修饰不同
 *
 *  比如：
 *
    Salmon:ms user$ diff c.txt  cpp.txt

    2c2
    < 0000000100003f30 <_add>:     // c下的修饰规则： _函数名
    ---
    > 0000000100003f30 <__Z3addii>: // cpp下的修饰规则：_Z + 函数字符长度 + 函数名 + 类型首字母
                                      (注意：没有返回值标识！所以，若仅仅只有返回值不同，其他都相同，则不构成函数重载)
    19c19
    < 0000000100003f50 <_func>:
    ---
    > 0000000100003f50 <__Z4funcidPi>:

 *
 *  编译、反编译结果：
 *  gcc -o testc fun_override.c
 *  objdump -S testc >./c.txt
 *
 *  gcc -o testcpp fun_override.c(其实这里用"fun_override.cpp"的结果一样！)
 *  objdump -S testcpp > ./cpp.txt
 *
 */


/**
 *  extern “C”
 *
 *  cpp文件本来编译后，是按照c++的规则来修饰的，但是这样的接口，
 *  无法被c引用，因此就要改变修饰规则，使用c的方式，就能被c引用了。
 *
 *  有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern “C”，意思是告诉编译器，
    将该函数按照C语言规则来编译。比如：tcmalloc是google用C++实现的一个项目，他提供tcmallc()和tcfree
    两个接口来使用，但如果是C项目就没办法使用，那么他就使用extern “C”来解决。
 *
 */
int add(int a, int b) {
    return a+b;
}

void func(int a, double b, int* p) {

}

int main() {
    add(1,2);
    func(1,2,0);
    return 0;
}

