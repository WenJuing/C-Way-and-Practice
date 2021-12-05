// 找出10000以内的自然数的所有完数，并统计完数个数
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int n, sum, i, count = 0, m;
    for (n = 2; n <= 10000; n++)
    {
        sum = 1;
        m = sqrt(n);    // ①
        for (i = 2; i <= m; i++)
            if (n % i == 0)
                sum += i + n/i;
        if (n == m*m)
            sum -= m;   // ②
        if (n == sum)
        {
            printf("%d\n", n);
            count++;
        }
    }
    printf("完数个数为：%d\n", count);
    system("pause");
    return 0;
}