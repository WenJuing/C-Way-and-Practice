// 通过递归算法计算Fibonachi数列
#include <stdio.h>
#include <windows.h>

int Fibo(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Fibo(n));
    system("pause");
    return 0;
}
int Fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fibo(n-1)+Fibo(n-2);
}