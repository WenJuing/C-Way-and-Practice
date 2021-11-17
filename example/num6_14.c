// 有0、1、2、3、4，能组成多少个互不相同且无重复数字的3位数？并输出这些3位数
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, k, count = 0;;
    for (i = 1; i <= 4; i++)
        for (j = 0; j <= 4; j++)
            for (k = 0; k <= 4; k++)
                if (i != j && i != k && j != k)
                {
                    printf("%d ", i*100+j*10+k);
                    count++;
                    if (count % 10 == 0) putchar('\n');
                }
    printf("\n共有%d个3位数\n", count);
    system("pause");
    return 0;
}