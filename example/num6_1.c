// 输入一个自然数，判断几位数，并逆序输出各位数字
#include <stdio.h>
#include <windows.h>
int main()
{
    int count=0, num;
    num = 0;
    while (num)
    {
        putchar(num%10 + '0');
        num /= 10;
        count++;
    }
    if (num == 0) putchar('0');
    printf("\n%d位\n", count);
    system("pause");
    return 0;
}
