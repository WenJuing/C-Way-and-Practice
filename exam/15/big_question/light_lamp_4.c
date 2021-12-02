#include <stdio.h>
#include <windows.h>
#include <math.h>
#define N 10
int main()
{
    int i, j, lamp[N+1], people[N+1];
    for (i = 1; i <= N; i++)
        lamp[i] = 1;
    for (i = 1; i <= N; i++)
        people[N] = i;
    // 一号经过，灯全灭
    for (i = 1; i <= N; i++) lamp[i] = 0;
    // 二号经过，偶数号的灯开
    for (i = 2; i <= N; i+=2) lamp[i] = 1;
    // 三~N号经过，对其倍数号的灯的开关做取反操作 
    for (i = 3; i <= N; i++)
    {
        for (j = i; j <= N; j += i)
        {
            if (lamp[j] == 1) lamp[j] = 0;
            else lamp[j] = 1;
        }
    }
    printf("显示结果：\n");
    printf("灯号  亮着\n");
    for (i = 1; i <= N; i++)
        if (lamp[i]) printf("  %-5d1\n", i);
    system("pause");
    return 0;
}