#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, k, B = 8, C = 1;  // B控制空格个数，C控制字符个数
    for (i = 1; i <= 9; i++)
    {
        for (j = 0; j < B; j++) putchar(' ');
        for (k = 0; k < C; k++) putchar('#');
        if (i >= 5)
            {B += 2;C -= 2;}
        else 
            {B -= 2;C += 2;}
        putchar('\n');
    }
    system("pause");
    return 0;
}