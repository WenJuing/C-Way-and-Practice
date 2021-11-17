// 找出10000以内的自然数中的所有完数，并统计个数。
// 完数：6 = 1 + 2 + 3，28 = 1 + 2 + 4 + 7 + 14
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, sum, cnt = 0;
    for (i = 2; i < 10000; i++)
    {
        sum = 0;
        for (j = 1; j <= i/2; j++)
            if (i % j == 0) sum += j;
        if (sum == i)
        {
            cnt++;
            printf("%d ", i);
            if (cnt % 10 == 0) putchar('\n');
        }
    }
    printf("\n10000以内完数的个数：%d\n", cnt);
    system("pause");
    return 0;
}