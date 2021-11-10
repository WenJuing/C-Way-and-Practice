// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>
int main()
{
    int w=2, k, f(int);
    for (k=0; k<3; k++)
    {
        w=f(w);
        printf("w=%d\n", w);
    }
    system("pause");
    return 0;
}
int f(int x)
{
    int y;
    y=++x;
    y+=x;
    return (y);
}