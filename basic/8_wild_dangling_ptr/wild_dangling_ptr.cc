int main ()
{
    // 野指针, 即指向未分配内存的指针
    int* ptr;
    *ptr = 10;

    // 垂悬指针, 即指向已释放内存的指针
    int *ptr2 = new int(10);
    delete ptr2;
    *ptr = 101;
    return 0;
}