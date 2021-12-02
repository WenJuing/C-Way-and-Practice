#include <stdio.h>
#include <windows.h>
#define M 4
#define NUM (M+1)*(M)/2
int main()
{
    int a[NUM], *p[M], i, j, index, n;
    for (i = 0; i < M; i++)
    {
        index = i * (i+1) / 2;
        p[i] = &a[index];
    }
    for (i = 0; i < M; i++)
    {
        n = 6;
        for (j = 0; j <= i; j++)
        {
            p[i][j] = i * M + n;
            n++;
        }
    }
    printf("Output:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%4d", p[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}