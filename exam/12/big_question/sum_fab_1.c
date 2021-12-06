#include <stdio.h>
#include <windows.h>

int main()
{
    int a[21];
    float sum = 0.0;
    a[0] = a[1] = 1;
    for (int i = 1; i <= 20; i++)
        a[i+1] = a[i] + a[i-1];
    for (int i = 1; i <= 20; i++)
        sum += a[i] * 0.1 / a[i+1];
    printf("%.2f\n", sum);
    system("pause");
    return 0;
}