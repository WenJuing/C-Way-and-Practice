// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>
void fun(int x, int y, int z)
{
    z = 2 * x + 5 * y;
}
int main()
{
    int m = 50;
    fun(5, 2, m);
    printf("m=%d\n", m);
    system("pause");
    return 0;
}