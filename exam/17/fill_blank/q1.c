// 计算 0!+1!+2!+...+n!
#include <stdio.h>
#include <windows.h>
float fac(int n)
{
    float f;
    if (n < 0)
        printf("error");
    else if (n == 1 || n == 0)
        f = 1;
    else
        f = n * fac(n-1);   // ①
    return f;
}
int main()
{
    int i, n = 3;
    float sum = 0;
    for (i = 0; i <= n; i++)
        sum += fac(i);
    printf("The result is %15.0f\n", sum);
    system("pause");
    return 0;
}