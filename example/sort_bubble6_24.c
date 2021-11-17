// 对10个整数用冒泡排序进行升序排序并输出
#include <stdio.h>
#include <windows.h>
int main()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t;
    for (i = 1; i < 10; i++)
        for (j = 1; j < 10-i; j++)
            if (a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
    system("pause");
    return 0;
}