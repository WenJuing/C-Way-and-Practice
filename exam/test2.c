#include <stdio.h>
#include <windows.h>
#include <math.h>
char buffer[80];
char * int_to_hex(int n);
int main()
{
    int n;
    printf("输入一个十进制数字：");
    scanf("%d", &n);
    printf("十进制为：%s\n", int_to_hex(n));
    system("pause");
    return 0;
}
char * int_to_hex(int n)
{
    static int i = 0;
    if (n < 16)
    {
        if (n < 10)
            buffer[i] = n + '0';
        else
            buffer[i] = n - 10 + 'A';
        buffer[i+1] = '\0';
    }
    else
    {
        int_to_hex(n / 16);
        n %= 16;
        i++;
        if (n < 10)
            buffer[i] = n + '0';
        else
            buffer[i] = n - 10 + 'A';
    }
    return buffer;
}