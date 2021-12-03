// 计算f(n) = 3^(n-1) / n!
#include <stdio.h>
#include <windows.h>
#include <math.h>
int faci(int n)
{
    if (n==1 || n==0)
        return 1;
    else return n*faci(n-1);
}
float f(int n)
{
    if (n==1 || n==0)
        return 1;
    else
        return pow(3,n-1) / faci(n);
}
float ff(int n)
{
    if (n == 1 || n==0)
        return 1/3*1.0;
    else
        return (3/n*1.0)*ff(n-1);
}
int main()
{
    printf("%f\n", f(3));
    printf("%f\n", ff(3));
    system("pause");
    return 0;
}