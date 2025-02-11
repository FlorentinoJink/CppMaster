#include <memory>
#include <format>
#include <iostream>

int main()
{

    // 1.release方法
    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    int *raw_p1 = p1.release();
    std::cout << std::format("p1: {}\n", *raw_p1);

    // release()将智能指针p1置为nullptr，返回raw_p1的内存地址
    // *p1 = 10;
    // std::cout << std::format("p1: {}\n", *p1);

    // 2.reset方法
    std::shared_ptr<int> p2(new int(42));
    p2.reset(new int(101));
    std::cout << std::format("p2: {}\n", *p2);

    p2.reset();
    // reset 销毁对象

    return 0;
}