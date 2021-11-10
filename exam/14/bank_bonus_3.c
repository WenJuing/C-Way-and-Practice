#include <stdio.h>
#include <windows.h>
int main()
{
    float r = 0.1475, n = 1e5;
    int y = 0;
    while (n <= 2e5)
    {
        y++;
        n *= (1 + r);
    }
    printf("year=%d, account=%f\n", y, n);
    system("pause");
    return 0;
}