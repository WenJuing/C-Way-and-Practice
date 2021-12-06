#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
    float x, x1, x2;
    printf("请输入要计算的数：");
    scanf("%f", &x);
    x2 = x;
    do {
        x1 = x2;
        x2 = (2 * x1 + x / (x1 * x1)) / 3;
    } while (fabs(x1 - x2) >= 1e-6);
    printf("%f\n", x1);
    system("pause");
    return 0;
}