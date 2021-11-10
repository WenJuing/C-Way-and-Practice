#include <stdio.h>
#include <windows.h>

int main()
{
    int d, m, y, flag = 0;
    printf("输入三个正整数，分别代表日 月 年：");
    scanf("%d %d %d", &d, &m, &y);
    // 判断是否在正确的范围
    if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y > 0)
    {
        // 偶数月，最多30天
        if (m % 2 == 0)
        {
            // 单独判断2月
            // 若润年，则二月最多29天
            if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
            {   
                if (m == 2 && d <= 29) flag = 1;
            }
            else    // 非闰年
            {
                if (m == 2 && d <= 28) flag = 1;
            }
            if (d <= 30 && m != 2) flag = 1;
        }
        else flag = 1;
    }
    if (flag) printf("是合理的日期\n");
    else printf("不是合理的日期\n");
    system("pause");
    return 0;
}