#include <iostream>

// 用于演示 dynamic_cast 的类层次结构
class Base {
public:
    virtual ~Base() {} // 确保 Base 是多态的
};

class Derived : public Base {};

void demonstrateStaticCast() {
    double d = 3.14;
    int i = static_cast<int>(d); // 将double转换为int
    std::cout << "static_cast: double to int -> " << i << std::endl;
}

void demonstrateDynamicCast() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b); // 安全向下转换
    if (d) {
        std::cout << "dynamic_cast: Successfully casted to Derived." << std::endl;
    } else {
        std::cout << "dynamic_cast: Cast failed." << std::endl;
    }
    delete b;
}

void demonstrateConstCast() {
    const int x = 5;
    int* nonConstX = const_cast<int*>(&x); // 移除const属性
    *nonConstX = 10; // 修改值，但行为未定义
    std::cout << "const_cast: Original value of x -> " << x << std::endl;
    std::cout << "const_cast: Modified value via non-const pointer -> " << *nonConstX << std::endl;
}

void demonstrateReinterpretCast() {
    int x = 100;
    int* pInt = &x;
    float* pFloat = reinterpret_cast<float*>(pInt); // 强制转换为float*

    std::cout << "reinterpret_cast: Value via int pointer -> " << *pInt << std::endl;
    // 注意：这里输出的结果依赖于系统的字节序和float的实际表示方式
    std::cout << "reinterpret_cast: Value via float pointer -> " << *pFloat << std::endl;
}

int main() {
    // 展示 static_cast
    demonstrateStaticCast();

    // 展示 dynamic_cast
    demonstrateDynamicCast();

    // 展示 const_cast
    demonstrateConstCast();

    // 展示 reinterpret_cast
    demonstrateReinterpretCast();

    return 0;
}