// 用迭代法计算sqrt(a)
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int count = 0;
    double x1, x2, a;
    a = 5;
    x2 = a;
    do {
        x1 = x2;
        x2 = 0.5 * (x1 + a/x1);
        count++;
    } while (fabs(x1-x2) > 1e-5);
    printf("sqrt(%f)=%f,count=%d\n", a, x1, count);
    x2 = a;
    count = 0;
    do {
        x1 = x2;
        x2 = 1 + (a-1) / (x1+1);
        count++;
    } while (fabs(x1-x2) > 1e-5);
    printf("sqrt(%f)=%f,count=%d\n", a, x1, count);
    system("pause");
    return 0;
}