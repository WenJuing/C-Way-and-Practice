#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    double a, x1, x2;
    printf("输入一个正数：");
    scanf("%lf", &a);
    x2 = a / 2;
    do {
        x1 = x2;
        x2 = 1 + (a - 1) / (1 + x1);
    } while (fabs(x1-x2) >= 1e-6);
    printf("结果为：%f\n", x1);
    system("pause");
    return 0;
}