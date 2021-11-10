#include <stdio.h>
#include <windows.h>

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
            putchar(i + '0');
        putchar('\n');
    }
    system("pause");
    return 0;
}