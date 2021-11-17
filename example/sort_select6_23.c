// 对10个整数用选择排序进行降序排序并输出
#include <stdio.h>
#include <windows.h>
int main()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t, max_index;
    for (i = 0; i < 10; i++)
    {
        max_index = i;
        for (j = i; j < 10; j++)
        {
            if (a[j] > a[max_index])    // 找到最大的一个数的下标
            {
                max_index = j;
            }
        }
        if (a[max_index] != a[i])  // 若找到最大的数，则交换
        {
            t = a[i];
            a[i] = a[max_index];
            a[max_index] = t;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
    system("pause");
    return 0;
}