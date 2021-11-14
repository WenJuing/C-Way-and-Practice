// 用迭代法求x = √a，求平方根的迭代公式为Xn+1 = (1/2)(Xn + a/Xn)
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    float a, x1, x2;
    printf("输入一个整数：");
    scanf("%f", &a);
    x2 = a;
    do
    {
        x1 = x2;
        x2 = (1.0/2) * (x1 + a / x1);
    } while (fabs(x1-x2)>1e-6);
    printf("结果为：%f", x1);
    system("pause");
    return 0;
}