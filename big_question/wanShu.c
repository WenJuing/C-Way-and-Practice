#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, n, sum;
    // 找到1000以内所有的完数
    for (n = 2; n < 1000; n++)
    {
        sum = 1;
        for (j = 2; j <= n / 2; j++)
            if (n % j == 0) sum += j;
        if (sum == n)
        {
            printf("%d its factors are 1 ", n);
            for (j = 2; j <= n/2; j++)
                if (n % j == 0) printf("%d ", j);
            printf("\n");
        }
    }
    system("pause");
    return 0;
}