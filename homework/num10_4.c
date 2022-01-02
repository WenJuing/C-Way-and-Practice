// 输入一个自然数，输出该自然数所有拆分的组合，例如：
// 5=1+1+1+1+1
// 5=1+1+1+2
// 5=1+2+2
// 5=1+4
// 5=2+3
#include <stdio.h>
#include <windows.h>
int main()
{
    int i = 1;
    while (i <= 15)
        if (++i%3!=2) continue;
        else printf("%d    ", i);
    putchar(10);
    system("pause");
    return 0;
}