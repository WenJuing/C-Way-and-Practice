#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
    double x = 8, x1, x2;
    x1 = 1.0;
    x2 = (2 * x1 + x / (x1 * x1)) * (1 / 3.0);
    do {
        x1 = x2;
        x2 = (2 * x1 + x / (x1 * x1)) * (1 / 3.0);
    } while (fabs(x1 - x2) < 1e-6);
    printf("%lf\n", x1);
    system("pause");
    return 0;
}