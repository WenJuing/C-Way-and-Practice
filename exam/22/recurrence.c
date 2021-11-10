// 有关递归函数的使用
#include <stdio.h>
#include <windows.h>
// 通过递归算法求解Hanoi塔（汉诺塔）问题
void hanoi(int n, char a, char b, char c); 
// 求解第n位斐波那契数列
int Fibo(int n);
int main()
{
    int n;
    scanf("%d", &n);
    // hanoi(n, 'a', 'b', 'c');
    printf("%d\n", Fibo(n));
    system("pause");
    return 0;
}
void hanoi(int n, char a, char b, char c)
{
    if (n>0)    // 若无盘可移动，则终止移动
    {
        // 将n-1个盘从a借c移到b
        hanoi(n-1, a, c, b);
        // 将n号盘从a移到c
        printf("Move disc:%d from %c to %c\n", n, a, c);
        // 将n-1个盘从b借a移到c
        hanoi(n-1, b, a, c);
    }
}
int Fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fibo(n-1)+Fibo(n-2);
}