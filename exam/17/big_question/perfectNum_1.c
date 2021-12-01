#include <stdio.h>
#include <Windows.h>
// 输出10000以内的完数（完数：因子之和为本身 6 = 1 + 2 + 3）
int main()
{
    int sum;
    for (int i = 1; i <= 10000; i++)
    {
        sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
                sum += j;
        }
        if (sum == i) printf("%d\n", i);
    }
    system("pause");
    return 0;
}