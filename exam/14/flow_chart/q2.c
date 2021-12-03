// 输出满足abcd=ab*b+c*d*d的所有四位数
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, a, b, c, d;
    for (i = 1000; i < 10000; i++)
    {
        a = i / 1000;
        b = i / 100 % 10;
        c = i / 10 % 10;
        d = i % 10;
        if (i == a*b*b+c*d*d)
            printf("%d*%d*%d+%d*%d*%d=%d\n",a,b,b,c,d,d,i);
    }
    system("pause");
    return 0;
}