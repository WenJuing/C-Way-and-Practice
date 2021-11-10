// 写出程序运行的结果
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