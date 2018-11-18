//
// Created by Salmon on 2018/11/2.
//

// 注意这里的用法，参考：https://www.cnblogs.com/liangxiaxu/archive/2012/09/02/2667730.html
extern "C"{
    #include "xinda.h"
}
#include <iostream>
using namespace std;

namespace com_xmly_native {

/*
 *
 * 参考：
 * C++构造函数初始化列表与构造函数中的赋值的区别:
 * https://blog.csdn.net/chenlycly/article/details/53558675
 * */
class Param{
public:
    Param(int type = 10){
        cout << "这里是类Param的构造函数.addr:" << this << endl;
        m_type = 10;
    }

    /*
     * 拷贝构造函数
     * 在此处进行"深拷贝"操作。
     *
     * 调用时间：
     * 用一个对象来初始化另一个对象
     *
     * 注意：
     * 也有默认的拷贝构造函数，只是进行"浅拷贝"。
     * 当成员变量包括指针时，仅传递指针值，即两个对象共享一个指针。
     *
     * */
    Param(Param &other){
        cout << "这里是类Param拷贝构造函数" << endl;
//        cout << "当前对象：" << this << " 传入对象：" << &other << endl;
        m_type = other.m_type;
    }

    //重载赋值=函数
    Param & operator =(Param &other){
        cout << "这里是 重载赋值=函数 " << endl;
//        cout << "当前对象：" << this << " 传入对象：" << &other << endl;
        m_type = other.m_type;
        return *this;
    }

private:
    int m_type;
};

class Point{
public:
        //在类内对成员函数进行声明
        void setPoint(int x, int y);

        // 在类定义时定义成员函数
        void printPoint()
        {
            cout<< "x = " << xPos << " y = " << yPos << endl;
        }

    /*
     * 1. "赋值方式"初始化成员对象m_food
     *
     *  这里是类Param的构造函数.addr:0x7ffeeef137d8
        这里是类Param的构造函数.addr:0x7ffeeef137d0
        这里是包括参数Param的构造函数
        这里是 重载赋值=函数
     *
     * 结果：
     *  m_param:0x7ffee2b047d0 param:0x7ffee2b047d8
        这里是 重载赋值=函数
        m_param:0x7ffee2b047d0 param:0x7ffee2b047d8
       结论：
        对象在赋值后，地址未发生变化！
        原因在于重载的赋值函数中的操作！
     * */
//    Point(Param &param){
//        cout << "这里是包括参数Param的构造函数" << endl;
//        cout << "m_param:" << &m_param << " param:" << &param << endl;
//        m_param = param;
//        cout << "m_param:" << &m_param << " param:" << &param << endl;
//    }

    /*
     * 相比较第一种方式，这种方式的效率更高！
     *
     * 2. "构造函数初始化列表方式"初始化包括自定义数据类型成员的对象
     *
     *  这里是类Param的构造函数.addr:0x7ffee51c57d8
        这里是拷贝构造函数
        这里是初始化列表方式m_param的构造函数
     * */
    Point(Param &param):m_param(param){
        cout << "这里是初始化列表方式m_param的构造函数" << endl;
    }

    /*
     * 初始化列表初始化
     * */
    Point(int x, int y):xPos(x),yPos(y)
    {
        cout << "这里是带初始化列表的构造函数" << endl;
    }

    /*
     * 函数体内初始化
     * 与上述"初始化列表"方法，二选一，不能共存
     * */
//    Point(int x, int y){
//        xPos = x;
//        yPos = y;
//    }

    Point(){
        cout << "这里是Ponit构造函数" << "x:" << xPos << " y:" << yPos << endl;
    }

    ~Point(){
        cout << "这里是Ponit析构函数" << "x:" << xPos << " y:" << yPos << endl;
    }
protected:

private:
        int xPos;
        int yPos;
        Param m_param;

};

//通过作用域操作符 '::' 实现setPoint函数
void Point::setPoint(int x, int y) {
    xPos = x;
    yPos = y;
}

class SubPoint:public Point{
public:
    SubPoint(int x, int y, int type):
            Point(x,y),
            zPos(111) // 类中const常量，必须在初始化列表中初始，不能使用赋值的方式初始化
    {
//        zPos = 111; // 错误。const变量无法赋值
        cout << "这里是SubPoint的构造函数" << endl;
    }
    ~SubPoint(){
        cout << "这里是SubPoint的析构函数" << endl;
    }

private:
    const int zPos;
};
    /*
     * 命名空间：
     * 防止"域"中的类、变量、函数冲突；
     * 区分模块功能
     * */
    namespace ns1{
        int x = 100;
    }

    namespace ns2{
        float x = 100.1;
    }

    void testNameSpace() {
        using namespace ns1;
        cout << x << endl;
        cout << ns2::x << endl;
        using namespace ns2;
//        cout << x << endl; //
// error: reference to 'x' is ambiguous
// 当需要引入另一个相同名称的变量时，需要加上作用域限定符，否则会冲突
        cout << ns2::x << endl;
    }
} // namespace com_xmly_native

using namespace com_xmly_native;

    void initialize()
{
    cout << "This is called by initialize() method" << endl;
    Point M;
    M.setPoint(10,20);
    M.printPoint();

    Point N(1,2);
    N.printPoint();

    SubPoint subPoint(3,4,10);
    subPoint.printPoint();

    // 包含有自定义数据类型"Param"（类）对象的成员初始化
    Param param;
    Point L(param);

    testNameSpace();

    return;
}

