#include <stdio.h>
#include <windows.h>
#define N 5
int main()
{
    int i, j;
    for (i=1;i<=N;i++)
    {
        for (j=1;j<=2*i-1;j++) putchar('A'+i-1);
        printf("\n");
    }
    system("pause");
    return 0;
}