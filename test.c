#include <stdio.h>
#include <windows.h>
#include <math.h>
#define N 100
void bao_shu(int n);
int main ()
{   
    int n;
    scanf("输入一个不大于%d的排队人数：", N);
    scanf("%d", &n);
    bao_shu(n);
    system("pause");
    return 0;
}
void bao_shu(int n)
{
    int i, cur = 0, cout, a[N+1], *p = a;
    for (i = 0; i < n; i++)
        a[i] = i+1;
    for (i = 0; i < n-1; i++) // 控制出队人数
    {
        for (cout = 0; cout < 3; cur++, cur %= n) // 报数形式：3个一循环
        {
            if (a[cur] != 0)
                cout++;
            if (cout == 3)
            {
                printf("%3d", a[cur]);
                a[cur] = 0;
            }
        }
    }
    while (*p == 0)
        p++;
    printf("\n最后剩下的是%d号\n", *p);
}
