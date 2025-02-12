#include <iostream>
#include <stdio.h>

int main()
{
    int *ptr = new int; // 分配并初始化一个整型变量
    *ptr = 10;
    std::cout << *ptr << std::endl;
    delete ptr; // 释放内存

    int *ptr2 = (int *)malloc(sizeof(int)); // 只分配内存，未初始化
    *ptr2 = 10;
    printf("%d\n", *ptr2);
    free(ptr2); // 释放内存
    return 0;
}