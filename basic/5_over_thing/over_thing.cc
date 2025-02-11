#include <iostream>

void display(int x)
{
    std::cout << "Integer: " << x << std::endl;
}

void display(double x)
{
    std::cout << "Double: " << x << std::endl;
}

void display(int x, double y)
{
    std::cout << "Integer and Double: " << x << ", " << y << std::endl;
}

class Base
{
public:
    virtual void show() const
    {
        std::cout << "Base class show()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void show() const override
    { // 使用 override 关键字明确表示重写
        std::cout << "Derived class show()" << std::endl;
    }
};

class Base2
{
public:
    void show() const
    {
        std::cout << "Base class show()" << std::endl;
    }

    void show(int x) const
    {
        std::cout << "Base class show(int)" << std::endl;
    }
};

class Derived2 : public Base2
{
public:
    void show() const
    {
        std::cout << "Derived class show()" << std::endl;
    }
};
int main()
{
    // 重载 overload
    display(5);       // 调用 void display(int)
    display(3.14);    // 调用 void display(double)
    display(2, 4.56); // 调用 void display(int, double)

    {
        // 重写 overwrite
        Base *basePtr = new Derived();
        basePtr->show(); // 输出 "Derived class show()"
        delete basePtr;
    }

    // 重定义
    Derived2 d;
    d.show(); // 调用 Derived::show()
    // d.show(5); // 编译错误：Derived::show 隐藏了 Base::show(int)

    Base2 *basePtr2 = &d;
    basePtr2->show();  // 调用 Base::show()
    basePtr2->show(5); // 调用 Base::show(int)
    return 0;
}