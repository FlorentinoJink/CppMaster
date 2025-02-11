#include <iostream>

static int globalVar = 10; // 全局静态变量 仅编译单元内可见

void func()
{
    static int count = 0; // 局部静态变量， 延长生命周期，但是作用域不变
    ++count;
    std::cout << "Count: " << count << std::endl;
}

class Example
{
public:
    static int sharedVar; // 声明静态成员变量，没有this指针，虚函数表中也不会存在
public:
    static void display() { std::cout << "Static function" << std::endl; } // 静态成员函数，同样也没有this指针，虚函数表中也不会存在
};
int Example::sharedVar = 0; // 定义及初始化

int main()
{
    return 0;
}