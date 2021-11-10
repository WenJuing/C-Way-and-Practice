#include <stdio.h>
#include <windows.h>
#define N 10
int main()
{
    int i, q[11], k, len = N;
    for (i = 1; i <= N; i++) q[i] = i;
    i = 3;
    k = 1;
    printf("出队顺序：");
    while (len > 2)
    {
        if (q[i] != 0) k++;
        if (k == 2)
        {
            q[i] = 0;
            len--;
            k = 0;
            printf("%3d", i);
        }
        i++;
        if (i == 11) i = 1;
    }
    printf("剩余2人的初始位置：");
    for (i = 1; i <= N; i++)
        if (q[i] != 0) printf("%3d", i);
    putchar(10);
    system("pause");
    return 0;
}