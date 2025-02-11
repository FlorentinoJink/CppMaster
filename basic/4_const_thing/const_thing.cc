#include <iostream>

class MyClass {
    const int data; // 常量成员变量，初始化后不可更改
    mutable int cache; // 可变成员变量，在const成员函数中也可以修改

public:
    // 构造函数，用于初始化data和cache
    MyClass(int d) : data(d), cache(0) {}

    // const成员函数，保证不会修改类的成员变量（除了mutable成员）
    int getData() const { 
        std::cout << "getData called" << std::endl;
        cache = 10; // 允许修改，因为cache被声明为mutable
        return data;
    }

    // const成员函数，但可以修改mutable成员变量cache
    void setCache(int c) const { 
        cache = c;
    }
};

int main() {
    // 创建一个常量对象obj，其值为100
    const MyClass obj(100);
    
    // 调用const成员函数getData，输出data的值
    std::cout << obj.getData() << std::endl;
    
    // 通过常量对象调用const成员函数setCache，修改cache的值
    obj.setCache(20); 
    

    int a = 10; // 或者 int const a = 10;

    int* const b = &a; // 常量指针
    const int* c = &a; // 指针常量
    const int* const p = &a; // 指向常量的常量指针
    
    return 0;
}