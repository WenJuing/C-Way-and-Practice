#include <stdio.h>
#include <windows.h>
#include <string.h>
#define N 3
void sum(int (*s)[8]);
int main()
{
    int i, j, score[N][8] = {0};
    printf("输入%d位学生的7门成绩：\n", N);
    for (i = 0; i < N; i++)
        for (j = 1; j < 8; j++)
            scanf("%d", &score[i][j]);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%5d", score[i][j]);
        putchar('\n');
    }
    sum(score);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%5d", score[i][j]);
        putchar('\n');
    }

    system("pause");
    return 0;
}
void sum(int (*s)[8])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 1; j < 8; j++)
            s[i][0] += s[i][j];
}