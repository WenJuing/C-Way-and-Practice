#include <stdio.h>
#include <windows.h>
#define N 8
int fibo(int n)
{
    if (n==1 || n==2)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}
int main()
{
    int i, s = 0;
    for (i = 1; i <= N; i++)
        s += fibo(i);
    printf("结果是：%d\n", s);
    system("pause");
    return 0;
}