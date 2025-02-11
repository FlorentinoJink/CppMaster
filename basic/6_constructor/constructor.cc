#include <utility>
#include <iostream>

class Example
{
private:
    int value;
    int *data; // 用于演示移动构造函数

public:
    // 默认构造函数
    Example();

    // 带参数的构造函数
    Example(int val);

    // 拷贝构造函数
    Example(const Example &obj);

    // 移动构造函数
    Example(Example &&other) noexcept;

    // 析构函数
    ~Example();

    void printValue() const;
};

// 默认构造函数
Example::Example() : value(0), data(nullptr)
{
    std::cout << "Default Constructor Called" << std::endl;
}

// 带参数的构造函数
Example::Example(int val) : value(val), data(new int(val))
{
    std::cout << "Parameterized Constructor Called" << std::endl;
}

// 拷贝构造函数
Example::Example(const Example &obj) : value(obj.value), data(new int(*(obj.data)))
{
    std::cout << "Copy Constructor Called" << std::endl;
}

// 移动构造函数
Example::Example(Example &&other) noexcept : value(other.value), data(other.data)
{
    other.data = nullptr;
    std::cout << "Move Constructor Called" << std::endl;
}

// 析构函数
Example::~Example()
{
    delete data;
    std::cout << "Destructor Called" << std::endl;
}

void Example::printValue() const
{
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    // 调用默认构造函数
    Example obj1;
    obj1.printValue();

    // 调用带参数的构造函数
    Example obj2(10);
    obj2.printValue();

    // 调用拷贝构造函数
    Example obj3 = obj2;
    obj3.printValue();

    // 调用移动构造函数
    Example obj4 = std::move(obj2);
    obj4.printValue();

    return 0;
}