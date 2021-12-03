#include <stdio.h>
#include <windows.h>
int main()
{
    int i, sum = 0, n, fac = 1;
    printf("输入一个正整数：");
    scanf("%d", &n);
    if (n == 0) sum = 1;
    else 
    {
        for (i = 1; i <= n; i++)
        {
            fac *= i;
            sum += fac;
        }
    }

    printf("结果为：%d\n", sum);
    system("pause");
    return 0;
}