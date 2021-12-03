#include <stdio.h>
#include <windows.h>
#define N 3
int main()
{
    int s=1, i, a[N][N]={1,2,3,4,5,6,7,8,9};
    for (i=0;i<N;i++) s*=a[N-i-1][i];
    printf("结果是：%d\n", s);
    system("pause");
    return 0;
}