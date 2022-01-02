// 输入出生日期和当前日期，计算周岁和距离下次生日的天数
#include <stdio.h>
#include <windows.h>
int cout_day(int y1, int m1, int d1, int y2, int m2, int d2);   // 计算两个日期之间的天数
int main()
{
    int birth_year, birth_month, birth_day, now_year, now_month, now_day, age, lest_day;
    printf("输入出生日期（年月日）：");
    scanf("%d %d %d", &birth_year, &birth_month, &birth_day);
    printf("输入当前日期（年月日）：");
    scanf("%d %d %d", &now_year, &now_month, &now_day);

    // 计算周岁
    age = now_year - birth_year;
    if (now_month < birth_month) age--;
    if (now_month == birth_month && now_day < birth_day) age--;
    // 计算天数
    if (now_month < birth_month);
    system("pause");
    return 0;
}
int cout_day(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int day = 0;
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (y2 > y1)
    {
        
    }
}