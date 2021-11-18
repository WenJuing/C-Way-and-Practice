// 输入年份和月份，输出这一月的日历
// 日 一 二 三 四 五 六
//    1  2  3  4  5  6
// 7  8  9  10 11  12 13
// 14 15 16 17 18 19 20
// 21 22 23 24 25 26 27
// 28 29 30
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, y, m, count = 0, month[12]={31,28,31,30,31,30,31,31,30,31,30};
    printf("请输入年份和月份：");
    scanf("%d %d", &y, &m);
    if (y%4==0 && y%100!=0 || y%400==0)
        month[1]++;
    printf("日\t一\t二\t三\t四\t五\t六\n\t");
    for (i=1; i <= 6; i++)  // 先输第一排
        printf("%d\t", i);
    printf("\n");
    for (i = 7; i <= month[m-1]; i++)
    {
        printf("%d\t", i);
        count++;
        if (count%7 == 0) putchar('\n');
    }
    printf("\n");
    system("pause");
    return 0;
}