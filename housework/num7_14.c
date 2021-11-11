// 求一个正整数的最大素数因子
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
bool is_prime(int n);
int main()
{
    int i, n, max = 0;
    scanf("%d", &n);
    for (i = 2; i < n; i++) // 判断小于数本身的数（要求素数，i从2开始）
        if (n % i == 0 && is_prime(i)) max = i; // 是因子且是素数
    printf("max=%d\n", max);
    system("pause");
    return 0;
}
bool is_prime(int n)
{
    int i;
    for (i = 2; i <= n/2; i++)
        if (n % i == 0) break;
    if (i > n/2) return true;
    else return false;
}