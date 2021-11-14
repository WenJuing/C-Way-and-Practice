// 公式：x2 = x1 – f(x1) / f’(x1)
// 用牛顿迭代法求根，方程为ax^3 + bx^2 + cx + d，系数abcd的值依次为1234。求x在1附近的一个实根。
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    float x1, x2, a, b, c, d;
    printf("依次输入a b c d的值：");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    x2 = 1;
    do {
        x1 = x2;
        x2 = x1 - (a*pow(x1,3) + b*x1*x1+c*x1+d) / (3*a*x1*x1+2*b*x1+c);
    } while (fabs(x1-x2) > 1e-6);
    printf("%f\n", x1);
    system("pause");
    return 0;
}