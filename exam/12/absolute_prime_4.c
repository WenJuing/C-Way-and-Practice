#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, k;
    for (i = 11; i < 100; i++)
    {
        k = i;
        // 判断是否为质数
        for (j = 2; j * j <= k; j++)
            if (k % j == 0) break;
        if (j * j > k)
        {
            // 个十位调换在判断是否为质数
            k = i / 10 + i % 10 * 10;
            for (j = 2; j * j <= k; j++)
                if (k % j == 0) break;
            if (j * j > k)
                printf("%d\n", i);
        }
    }
    system("pause");
    return 0;
}