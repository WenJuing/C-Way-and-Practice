#include <stdio.h>
#include <windows.h>
#define N 5
int main()
{
    int i, sum = 0;
    char you[N+1], res[N+1];
    printf("输入你的选项序列：\n");
    for (i = 0; i < N; i++)
    {
        you[i] = getchar();
    }
    you[i] = '\0';
    getchar();
    printf("输入答案序列：\n");
    gets(res);
    // 核对
    for (int i = 0; i < N; i++)
    {
        if (you[i] == ' ') {
            putchar('N');
            putchar('\n');
            continue;
        }
        if (you[i] == res[i])
        {
            sum += 2;
            printf("正确\n");
        }
        else
            printf("错误\n");
    }
    printf("你的总分：%d\n", sum);
    system("pause");
    return 0;
}