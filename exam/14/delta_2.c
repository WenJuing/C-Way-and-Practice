#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8 - i*2; j++) putchar(' ');
        for (j = 0; j < i*2 + 1; j++) putchar('#');
        putchar('\n');
    }
    for (i = 0; i < 9; i++) putchar('#');
    putchar('\n');
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < i*2 + 2; j++) putchar(' ');
        for (j = 0; j < 7 - i*2; j++) putchar('#');
        putchar('\n');
    }
    system("pause");
    return 0;
}