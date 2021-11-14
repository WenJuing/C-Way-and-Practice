#include <stdio.h>
#include <windows.h>

int main()
{
    int m, n, mul;
    scanf("%d %d", &m, &n);
    mul = m * n;
    while (m % n != 0)
    {
        if (m > n) m = m % n;
        if (m < n) n = n % m;
    }
    printf("最大公约数：%d，最小公倍数：%d\n", n, mul / n);
    system("pause");
    return 0;
}