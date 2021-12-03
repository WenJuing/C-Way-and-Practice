#include <stdio.h>
#include <windows.h>
#define N 5 // 学生数量
// 学生成绩：期末考试成绩、综合实验成绩、期中测验成绩、平时考核成绩
int main()
{
    int i, j;
    float s[N][5];  // 最后一格保存总评成绩
    int a[6] = {0};
    printf("输入%d名学生的四门成绩：\n", N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 4; j++)
            scanf("%f", &s[i][j]);
        s[i][4] = s[i][0] * 0.5 + s[i][1] * 0.2 + s[i][2] * 0.2 + s[i][3] * 0.1;
    }
    // 统计分段
    for (i = 0; i < 5; i++)
    {
        if (s[i][4] >= 90) a[0]++;
        else if (s[i][4] >= 80) a[1]++;
        else if (s[i][4] >= 70) a[2]++;
        else if (s[i][4] >= 60) a[3]++;
        else if (s[i][4] >= 50) a[4]++;
        else a[5]++;
    }
    printf("学生成绩：\n");
    printf("期末考试成绩\t综合实验成绩\t期中测验成绩\t平时考核成绩\t总评成绩\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%.2f\t", s[i][j]);
        putchar('\n');
    }
    printf("分段\t人数\t占比\n");
    printf("90~100 : %d\t%.2f%%\n", a[0], a[0]*100.0 / N);
    printf("80~89 : %d\t%.2f%%\n", a[1], a[1]*100.0 / N);
    printf("70~79 : %d\t%.2f%%\n", a[2], a[2]*100.0 / N);
    printf("60~69 : %d\t%.2f%%\n", a[3], a[3]*100.0 / N);
    printf("50~59 : %d\t%.2f%%\n", a[4], a[4]*100.0 / N);
    printf(" 0~49 : %d\t%.2f%%\n", a[5], a[5]*100.0 / N);
    system("pause");
    return 0;
}