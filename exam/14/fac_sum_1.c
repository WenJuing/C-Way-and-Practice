#include <stdio.h>
#include <windows.h>
int main()
{
    int i, sum = 0, fac = 1, n;
    printf("输入一个正整数：");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        fac *= i;
        sum += fac;
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}