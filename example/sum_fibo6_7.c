// 求2/1+3/2+5/3+8/5+...前20项和
#include <stdio.h>
#include <windows.h>
void sum_an();
int Fibo(int n);
void fun1();    // 方法1：直接求斐波那契数列的相关项，再直接算
void fun2();    // 方法2：找规律，再计算
int main()
{
    fun1();
    fun2();
    system("pause");
    return 0;
}
int Fibo(int n)
{
    if (n==2 || n==1)
        return 1;
    else return Fibo(n-1)+Fibo(n-2);
}
void fun1()
{
    int i;
    float sum = 0.0;
    for (i = 2; i <= 21; i++)
        sum += Fibo(i+1)*1.0 / Fibo(i);
    printf("方法一：前20项和为：%f\n", sum);
}
void fun2()
{
    // 设an = x/y，则an+1 = (x+y)/x
    int i, t;
    float x, y, sum = 0;
    x = 2, y = 1;
    for (i = 0; i < 20; i++)
    {
        sum += x / y;
        t = x;x = x + y; y = t;
    }
    printf("方法二：前20项和为：%f\n", sum);
}