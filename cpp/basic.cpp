//
// Created by Salmon on 2018/11/18.
//

extern "C"{
    #include "xinda.h"
}

#include <iostream>

using namespace std;

namespace com_xmly_native {

    class Person {
    public:
        Person() {
            name = new char[16];
            cout << "Person构造" << endl;
        }

        virtual ~Person() {
            delete []name;
            cout << "Person析构" << endl;
        }

        /*
         * virtual在修饰方法时，可以实现多态:
         * 即，子类有复写时，优先调用子类实现
         * */
        virtual void display() {
            cout << "Person display. " << endl;
        }

        /*
         * 考虑 "&"的作用？
         * */
        void swap(int &a, int &b){
            cout<< "int swap....." << endl;
            cout<< "a addr:" << &a <<endl;
            cout<< "b addr:" << &b <<endl;
            int tmp = a;
            a = b;
            b = tmp;
        }
        /*
         * 值传递不如地址传递高效?
         * 因为值传递先从实参的地址中取出值，再赋值给形参代入函数计算；
         * 而指针则把形参的地址直接指向实参地址，使用时直接取出数据，效率提高，特别在频繁赋值等情况下（注意：形参的改变会影响实参的值！）
         *
         * */

    private:
        char* name;
    };

    /*
     * 虚基类:
     *  virtual 修饰继承父类
     *  可以解决"二义性"的问题 ，就是解决多重多级继承造成的二义性问题。
     *
     * 二义性的根源：
     *  C++支持多继承。
     *  若不使用virtual，会构造子类时，会多次构造、多次析构父类。
     *  比如，在实例TS时，会多次构造Person，无法区分Person中的属性属于Teacher还是Student的。
     *
     * */
    class Teacher : virtual public Person {
    public:
        Teacher() {
            cout << "Teacher构造" << endl;
        }

        virtual ~Teacher() {
            cout << "Teacher析构" << endl;
        }

        void display() {
            cout << "Teacher display." << endl;
        }
    };

    class Student : virtual public Person {
    public:
        Student() {
            cout << "Student构造" << endl;
        }

        virtual ~Student() {
            cout << "Student析构" << endl;
        }
    };

    /*
     * C++支持多继承（不推荐，会增加代码复杂度）
     *
     * 构造顺序（多个父类时）：
     *  继承时的父类顺序
     *
     * 析构顺序：
     *  与构造顺序相反
     *
     * 比如：
     *  Person构造
        Teacher构造
        Student构造
        TS构造
        TS析构
        Student析构
        Teacher析构
        Person析构
     */
    class TS:public Teacher, public Student{
    public:
        TS() {
            cout << "TS构造" << endl;
        }

        virtual ~TS() {
            cout << "TS析构" << endl;
        }
    };
}

using namespace com_xmly_native;

void doDisplay(Person* person){
    person->display();
}

void virtualTest(){
    /*
 * 1. 多态：（virtual修饰方法时）
 * 有virtual修饰"display()"：
 *  Teacher display.
 * 无virtual：
 *  Person display.
 * */
    Person* person = new Teacher();
    doDisplay(person);
    delete(person);

    // 2. 虚继承：（virtual修饰继承父类时）
    TS ts;
//    TS* pointer = new TS;
//    delete  pointer;
}

/*
 * "*&i"表示"指针的引用传递"。即：
 * 1. 传递的是一个指针：可以修改指针指向的对象
 * 2. 该指针的一个引用：可以修改指针本身
 *
 * 与"*i"区分:
 * 仅传递指针值，指针本身不可修改！
 * */
void referTrans(int *&i){
    i = new int;
    *i = 10;
}

void paramsTransTest(){
    // 1. "&a"形参的用法
    Person* person1 = new Person;
    int a = 10;
    int b = 20;
    cout << "a addr:" << &a << endl;
    cout << "b addr:" << &b << endl;
    person1->swap(a, b);
    cout<< "a:"<<a<<endl;
    cout<< "b:"<<b<<endl;

    // 2. 引用传递. c与a具有相同的地址，形式上类似"值传递"
    int &c = a;
    cout << "c addr:" << &c << endl;
    assert(&c == &a);
    c = 100;
    cout << "a:" << a << endl;
    cout << "c:" << c << endl;

    // 3. "*&a"形参的用法
    int* p ;
    referTrans(p);
    cout << "*p:" << *p << endl;
    delete p;

    /*
     * 4. 指针和引用的区别:("引用可以被认为是不能改变的指针")
     *  a. 是否可变。指针可以被重新赋值指向另一个对象，引用初始化后始终指向原对象，只能改变对象值，无法改变指向关系，相当于"const类型"
     *  b. 是否需要内存。指针变量需要内存，引用不占用内存。因此引用声明时必须初始化，且不能为空值
     *  c. 效率不同。引用的效率更高。指针可能非法，使用前需要校验合法性；而不存在指向空值的引用，不需要校验合法性
     *  d. 理论上，对于指针的级数没有限制，但是引用只能是一级。
     * */
    int m = 10, l = 20;
    int &n = m;
//    int &n = l; // 失败，引用在初始化与对象绑定，无法改变
}

// 声明可以"形参名"
int add(int=3, int=5);

int add(int x, int y){
    return x + y;
}

void defaultParamTest(){
    cout << add() << endl; // 8
    cout << add(10) << endl; // 15
    cout << add(10,20) << endl; // 30
}

void enumTest(){
    /*
     * 语法结构：
　　    enum [枚举名] {e1[=Value1], e2[=Value2] ,… …}；
     *
     * 默认枚举值为：
     *  0,1,2....递增
     *
     * 枚举值注意：
     *  1. 不能为负数！
     *  2. 可以重复。比如，enum weeks {mon=1,tue=1,wed=1,thu=1,fri=1,sat=2,sun=2};
     *
     * */
    enum weekday {mon=1,tru,wed,thu,fri,sat,sun} day;
//    enum weekday {mon=1,tru,wed,thu=9,fri,sat,sun} day;
    // 此时 fri为10，依上个成员的枚举值依次递增的
    int k;
    printf("please input day num:");
    scanf("%d",&k);
    day = (weekday)k; // 整数需要"强制类型转换"才能赋值给枚举值
    cout << day << endl; // 输出：1、2、。。。,输出枚举值，而不是枚举常量名称
    switch (day){
        case mon:
        case tru:
        case wed:
        case thu:
        case fri:
            printf("今天上班.\n");
            break;
        case sat:
        case sun:
            printf("今天休息.\n");
            break;
        default:
            printf("错误的日期\n");
            break;
    }
}

void invokeBasic(){
    virtualTest();
    paramsTransTest();
    enumTest();
    defaultParamTest();
}