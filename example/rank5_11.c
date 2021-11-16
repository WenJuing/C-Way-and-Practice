// 某学生两门课成绩分别为x、y，按情况输出学生成绩评定
// 两门都大于等于90，输出“优秀”
// 两门都大于等于60，输出“合格”
// 仅有一门小于60，输出“较差”
// 两门都不合格，输出“很差”
#include <stdio.h>
#include <windows.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (x >= 90 && y >= 90)
        puts("优秀");
    else if (x >= 60 && y >= 60)
        puts("合格");
    else if (x >= 60 || y >= 60)
        puts("较差");
    else
        puts("很差");
    system("pause");
    return 0;
}