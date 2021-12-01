#include <stdio.h>
#include <windows.h>
#define N 9
int main()
{
    int a[N] = {36,8,55,96,23,13,62,15,17},b[N];
    int i;
    for (i=1; i<N; i++)
        b[i]=a[i]/a[i-1];
    for (i=1; i<N; i++)
        printf("%3d", b[i]);
    system("pause");
    return 0;
}