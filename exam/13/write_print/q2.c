#include <stdio.h>
#include <windows.h>
#define N 4
int main()
{
    int s=0,i,a[N][N]={3,4,5,6,16,17,18,19,24,25,26,27,33,34,35,36};
    for (i = 0; i < N; i++) s+=a[N-i-1][i]-a[i][i];
    printf("结果是：%d\n", s);
    system("pause");
    return 0;
}