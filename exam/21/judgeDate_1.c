#include <stdio.h>
#include <windows.h>

int main()
{
    int d, m, y, flag = 0, month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("输入三个正整数，分别代表日 月 年：");
    scanf("%d %d %d", &d, &m, &y);
    // 润年二月加一
    if (y%4==0 && y%100==0 || y%400==0)
        month[1]++;
    // 判断是否在正确的范围
    if (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= month[m-1]) flag = 1;    
    if (flag) printf("是合理的日期\n");
    else printf("不是合理的日期\n");
    system("pause");
    return 0;
}