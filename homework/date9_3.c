// 输入年月日，输出这个月还剩下几天
#include <stdio.h>
#include <windows.h>
int main()
{
    int y, m, d;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30};
    scanf("%d %d %d", &y, &m, &d);
    // 若闰年，则2月加一天
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        month[1]++;
    printf("这个月还剩%d天", month[m-1]-d);
    putchar(10);
    system("pause");
    return 0;
}