// 输入一个整数，计算与斐波那契数列最接近的那一个数字并输出
#include <stdio.h>
#include <windows.h>
int Fibo(int n);
int main()
{
    int i, n;
    scanf("%d", &n);
    // 寻找与n差值最小的Fibo数
    for (i = 1; n >= Fibo(i); i++);
    if ((Fibo(i)-n) > (n-Fibo(i-1))) printf("%d\n", Fibo(i-1));
    else printf("%d\n", Fibo(i-1));
    system("pause");
    return 0;
}
int Fibo(int n)
{
    if (n==1 || n==2)
        return 1;
    else
        return Fibo(n-1)+Fibo(n-2);
}