#include <iostream>

void func(int *ptr) {
    int val = 10;
    ptr = &val; // 修改形参ptr的指向
    // *ptr = 10； // 修改实参的指向
}

void func(int &ref) {
    int val = 11;
    ref = val; // 修改的是ref绑定的变量的值,而非重新绑定引用
}

int main()
{
    int a = 1;
    func(&a); // 传递指针
    std::cout << a << std::endl;

    func(a); // 传递引用
    std::cout << a << std::endl;
    return 0;
}
// 符号表逻辑
// 变量名   地址值             存储内容
// a       0x7fffdfffe0         1
// ptr     0x7fffdfffe4         0x7fffdfffe0
// ref     0x7fffdfffe0         别名无独立存储