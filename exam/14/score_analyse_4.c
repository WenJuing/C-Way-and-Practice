#include <stdio.h>
#include <windows.h>
#define N 5 // 学生数量
// 学生成绩：期末考试成绩、综合实验成绩、期中测验成绩、平时考核成绩
int main()
{
    int i, j;
    float s[5][5], (*p)[5] = s;
    int a[6] = {0};
    printf("输入%d名学生的四门成绩：\n", N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%f", * (p + i) + j);
        }
        s[i][4] = s[i][0] * 0.5 + s[i][1] * 0.2 + s[i][2] * 0.2 + s[i][3] * 0.1;
    }
    // 统计分段
    for (i = 0; i < 5; i++)
    {
        if (s[i][4] >= 90 && s[i][4] <= 100) a[0]++;
        else if (s[i][4] >= 80 && s[i][4] <= 89) a[1]++;
        if (s[i][4] >= 70 && s[i][4] <= 79) a[2]++;
        if (s[i][4] >= 60 && s[i][4] <= 69) a[3]++;
        if (s[i][4] >= 50 && s[i][4] <= 59) a[4]++;
        if (s[i][4] >= 0 && s[i][4] <= 49) a[5]++;
    }
    printf("学生成绩：\n");
    puts("期末考试成绩  综合实验成绩  期中测验成绩  平时考核成绩  总评成绩");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%7.2f", s[i][j]);
        putchar('\n');
    }
    puts("分段       人数    占比");
    printf("90~100 : %-5d%5.2f\n", a[0], a[0]*1.0 / N);
    printf("80~89 : %-5d%5.2f\n", a[1], a[1]*1.0 / N);
    printf("70~79 : %-5d%5.2f\n", a[2], a[2]*1.0 / N);
    printf("60~69 : %-5d%5.2f\n", a[3], a[3]*1.0 / N);
    printf("50~59 : %-5d%5.2f\n", a[4], a[4]*1.0 / N);
    printf("0~49 : %-5d%5.2f\n", a[5], a[5]*1.0 / N);
    system("pause");
    return 0;
}