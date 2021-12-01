#include <stdio.h>
#include <windows.h>
void trans(int n)
{
    int i;
    if ((i=n/10) != 0) trans(i);
    putchar((n%10)+'0');
    putchar(',');
}
int main()
{
    int num = 693;
    if (num < 0)
    {
        putchar('-');
        num = -num;
    }
    trans(num);
    printf("\n");
    system("pause");
    return 0;
}