// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>
int a=4;
int fun(int x)
{
    static int b = 5;
    int y = 1;
    y=y+a;
    a=b+4;
    b=x+y;
    return a+b+y;
}
int main()
{
    int m = 5, i;
    for (i=1;i<=3;i++)
        printf("i=%d,%d\n", i, fun(m));
    system("pause");
    return 0;
}