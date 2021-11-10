#include <stdio.h>
#include <Windows.h>

int main()
{
    int num;
    scanf("%d", &num);
    if (num > 0)
        putchar('+');
    else if (num < 0)
        putchar('-');
    else
        putchar('0');
    if (num < 0) num = -num;
    while (num > 0)
    {
        putchar(num % 10 + '0');
        num /= 10;
    }
    system("pause");
    return 0;
}