#include <stdio.h>
#include <windows.h>

int main()
{
    int d, m, y, flag = 0, month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("输入三个正整数，分别代表日 月 年：");
    scanf("%d %d %d", &d, &m, &y);
    // 判断是否在正确的范围
    if (y <= 0 || m <= 0 && m > 12 || d <= 0 && d > 31) flag = 0;
    if (month[m-1] >= d)
    {
        if (m == 2)
            if (y%4==0 && y%100==0 || y%400==0)
                if (d <= 29)
                    flag = 1;
    }
    if (flag) printf("是合理的日期\n");
    else printf("不是合理的日期\n");
    system("pause");
    return 0;
}