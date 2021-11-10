#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 5 - i; j >= 1; j--) putchar(' ');
        for (j = 1; j <= i*2 - 1; j++) putchar('*');
        putchar('\n');
    }
    
    system("pause");
    return 0;
}