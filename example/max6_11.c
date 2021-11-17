// 输入两个正整数，求最大公约数
#include <stdio.h>
#include <windows.h>
int main()
{
    int m, n;
    printf("输入两个正整数：");
    scanf("%d %d", &m, &n);
    while (m % n != 0)
    {
        if (m > n) m = m % n;
        if (n > m) n = n % m;
    }
    printf("最大公约数：%d\n", n);
    system("pause");
    return 0;
}