//
// Created by Salmon on 2022/3/28.
//

#include <iostream>

/**
 *
 * 突然奇想：为什么要设计"栈"呢？程序从头跑到尾，不香吗？
 *
 * 1. 便于内存回收
 *    栈中有函数，函数指定了局部变量，用完了就可以随时销毁
 *
 * 2. 允许嵌套
 *
 * 3. 方便对堆中的对象快速索引。
 *    速度快，仅次于寄存器。堆中都是大对象，没有栈中的对象指针，就要一一遍历，太慢了
 *
 * 4. 暂存断点地址，用于现场恢复
 *
 */

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


/**
 * 引用做参数
 *
 * @param a
 * @param b
 */
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 *
 * 引用做返回值
 *
 * 这里可以引用返回：因为出了函数，返回对象还在，未还给系统
 * @param a
 * @param b
 * @return
 */
int& add(int a, int b) {
    static int c = a + b; // "static局部变量只被初始化一次，下一次依据上一次结果值"
    return c;
}

// 这里要传值返回：因为出了函数，在栈里的局部变量返回对象还给了系统
int add2(int a, int b) {
    int c = a+b;
    return c;
}

/**
 * 引用
 * 变量的别名，没有单独内存空间
 *
 */
void reference() {
    int a = 1;
    int &b = a; // 给a起了一个别名b;
    cout << a << endl;
    cout << b << endl;

    b = 3; // 改变b相当于改变了a

    cout << a << endl;
    cout << b << endl;


//    int &c; 必须在定义时初始化！

    // 一个变量可以有多个引用
    int &c = a;
    int &d = a;

    int e = 10;
    d = e; // 这里只是赋值！只能被引用一次！
    cout << d << endl;
    cout << a << endl;

    int f = 10;
    /**
     * 为什么 "double &rf = f" 报错？
     *
     * int到double存在隐士类型的提升，
     * 而在提升的过程中系统会创建一个
     * 常量区来存放a类型提升后的结果
     *
     */
    const double &rf = f;

    int m = 10;
    int n = 20;
    swap(m, n);
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;

    int &ans = add(1,2);
    add(3,4);
    cout << "ans = " << ans << endl; // 还是"3"

    int p = 100;
    int &rp = p;

    cout << "&p  = "  << &p << endl;
    cout << "&rp = " << &rp << endl;
    /**
     *
     * "在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间"
     *
     * &p  = 0x7ffeeb456634
       &rp = 0x7ffeeb456634
     */
}

double TestAuto() {
    return 10.0;
}

/**
 *
 * auto
 *
 * 实际是类型声明时的"占位符"，在编译期对推导并替换实际类型
 *
 * 类型kotlin中的"var"
 */
void autoTest() {
    int a = 10;
    auto  b = a;
    auto  c = 'a';
    auto  d = TestAuto();
//    auto e;  // 编译失败！auto 定义变量时必须对其初始化

    cout << typeid(a).name() << endl; // 打印类型名
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;

    auto e = &a; // 推导e的类型为"int*"
    auto* f = &a;// 推导f的类型为"int*"，"auto*"和"auto"一样
    auto& g = a; // 推导g的类型为为int

    cout << typeid(e).name() << endl;
    cout << typeid(f).name() << endl;
    cout << typeid(g).name() << endl;

    auto  h = 1, i = 2; // 同一行定义多个变量，必须类型相同
//    auto  j = 3, k = 4.0; // 这里失败了！因为类型不同！

    int array[] = {1,2,3};
//    auto b[] = {4,5,6}; // auto不能直接用来声明数组

}

// 失败！auto不能作为形参！
//void errorAutoFunc(auto a) {}


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

    reference();

    autoTest();

}