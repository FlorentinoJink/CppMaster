#include <iostream>

void print(int x) { std::cout << "int: " << x; }
void print(double x) { std::cout << "double: " << x; }

class Animal
{
public:
    virtual void speak() { std::cout << "Animal sound\n"; }
};

class Dog : public Animal
{
public:
    void speak() override { std::cout << "Woof!\n"; }
};

int main()
{
    // 静态绑定 静态联编 函数名 参数类型直接匹配，编译时多态（重载，模板）
    print(5);    // 调用 print(int)
    print(3.14); // 调用 print(double)

    // 动态绑定 动态联编
    Animal *a = new Dog();
    a->speak(); // 输出 "Woof!"（动态绑定） 通过虚函数表实现 运行时多态（继承，虚函数）
    delete a;
    return 0;
    return 0;
}