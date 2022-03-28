//
// Created by Salmon on 2022/3/28.
//

#include <iostream>

/**
 * "命名空间"的目的就是对标识符和名称进行本地化，以避免命名冲突或名字污染
 *
 * 相当于java里的"package"
 *
 */
namespace xjt
{
    int printf = 1;
    // 普通的命名空间，可以定义变量，也可以定义函数
    int _random = 2;

    int add(int a, int b) {
        return a + b;
    }

    // 命名空间可以嵌套定义
    namespace xjt2
    {

        int a = 0;

        int sub(int a, int b) {
            return a - b;
        }
    }
}

// 命名空间相同时，编译器会合并到一起
namespace xjt
{
    int a = 3;

    int b = 1;
}

// 不建议这么用！会有"命名污染"问题。后面对"printf"的调用出现混淆！
//using namespace xjt;

using xjt::_random;
using xjt::b;
using namespace std;


// 半缺省/全缺省
void func(int a, int b, int c = 2) {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}


int main() {
    // "作用域限定符::"， “命名空间名称::命名空间成员”便可以访问到命名空间中相应的成员
    printf("%d\n", xjt::_random);

    printf("%d\n", _random);

    printf("%d\n", b);

    /**
     * C++中的输入和输出
     *
     * 比C语言的printf、scanf方便，C++的输入输出不需要控制格式%d、%c
     */
    int a = 1;
    float b = 2.1;
    double c = 2.111;
    char d[] = "hello world.";
    char arr[10] = {0};

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    // 这里输入"hello world."会被截断，只输出"hello". 因为cin是以"空格，tab或者换行符"作为分隔符的。
    // 类似"gets"，gets是遇到换行符停止
//    cin >> arr;
    cout << arr << endl;

    /**
     * "缺省参数"
     */
    func(1,3,5);
    func(10,20);

}