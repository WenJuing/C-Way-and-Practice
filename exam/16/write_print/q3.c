#include <stdio.h>
#include <windows.h>
#define N 9
long fsum(int n) {
    if (n==0) return 0;
    else return n+fsum(n-1);
}
int main()
{
    int i;
    int s = 0;
    for (i=1;i<=N;i=i+3)
        s=s-fsum(i);
    printf("结果是：%d\n", s);
    system("pause");
    return 0;
}