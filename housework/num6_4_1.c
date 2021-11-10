// 求abc+cba等于给定值n的所有a、b、c的组合
#include <stdio.h>
#include <windows.h>

int main()
{
    int a, b, c, n;
    scanf("%d", &n);
    for (a = 0; a <= n; a++)
        for (b = 0; b<=n; b++)
            for (c=0; c<=n; c++)
                if (a*100+b*10+c+c*100+b*10+a == n)
                    printf("%d%d%d+%d%d%d=%d\n",a,b,c,c,b,a,n);
    putchar(10);
    system("pause");
    return 0;
}