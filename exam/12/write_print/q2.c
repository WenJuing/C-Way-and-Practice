#include <stdio.h>
#include <windows.h>
#define N 8
int main()
{
    int i, a=1, b=1, s=1;
    for (i=1; i<=N/2; i++)
    {
        s=s+a+b;
        a=a+b;
        b=a+b;
    }
    printf("%d\n",s);
    system("pause");
    return 0;
}