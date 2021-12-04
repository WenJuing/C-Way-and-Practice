#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5-i; j++) putchar(' ');
        for (k = 1; k <= i*2 - 1; k++) putchar('*');
        putchar('\n');
    }
    system("pause");
    return 0;
}