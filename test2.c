// 测试
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    float x1, x2, a;
    printf("输入整数：", &a);
    scanf("%f", &a);
    x2 = a;
    do {
        x1 = x2;
        x2 = 0.5 * (x1 + a / x1);
    } while (fabs(x1-x2) >= 1e-5);
    printf("√%d=%f\n", a, x1);
    x2 = a / 2;
    do {
        x1 = x2;
        x2 = 0.5 * (x1 + a / x1);
    } while (fabs(x1-x2) >= 1e-5);
    printf("√%f=%f\n", a, x1);
    system("pause");
    return 0;
}