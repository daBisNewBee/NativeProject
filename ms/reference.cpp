//
// Created by Salmon on 2022/3/30.
//

/**
 *
 * 验证"引用表面上不占用额外空间，在底层实际占用空间，因为引用是按照指针方式来实现的"？
 *
    0000000100003f60 <__Z4fun1v>:
    100003f60: 55                           pushq   %rbp
    100003f61: 48 89 e5                     movq    %rsp, %rbp
    100003f64: c7 45 fc 0a 00 00 00         movl    $10, -4(%rbp)
    100003f6b: 48 8d 45 fc                  leaq    -4(%rbp), %rax
    100003f6f: 48 89 45 f0                  movq    %rax, -16(%rbp)
    100003f73: 48 8b 45 f0                  movq    -16(%rbp), %rax
    100003f77: c7 00 14 00 00 00            movl    $20, (%rax)
    100003f7d: 5d                           popq    %rbp
    100003f7e: c3                           retq
    100003f7f: 90                           nop

    0000000100003f80 <__Z4fun2v>:
    100003f80: 55                           pushq   %rbp
    100003f81: 48 89 e5                     movq    %rsp, %rbp
    100003f84: c7 45 fc 0a 00 00 00         movl    $10, -4(%rbp)
    100003f8b: 48 8d 45 fc                  leaq    -4(%rbp), %rax
    100003f8f: 48 89 45 f0                  movq    %rax, -16(%rbp)
    100003f93: 48 8b 45 f0                  movq    -16(%rbp), %rax
    100003f97: c7 00 14 00 00 00            movl    $20, (%rax)
    100003f9d: 5d                           popq    %rbp
    100003f9e: c3                           retq
    100003f9f: 90

    引用和指针的区别：
    1. 没有NULL引用，但有NULL指针。
    2. 有多级指针，但是没有多级引用
    3. 引用比指针使用起来相对更安全
 */
void fun1() {
    int a = 10;

    int &ra = a;
    ra = 20;
}

void fun2() {
    int a = 10;

    int *pa = &a;
    *pa = 20;
}



int main() {
    return 0;
}

