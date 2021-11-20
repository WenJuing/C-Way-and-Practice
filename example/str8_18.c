// 输出字串在母串第一次出现的位置
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char str[10]="chinayoo", sub[10]="hi";
    printf("%d\n", strstr(str, sub)-str+1);
    system("pause");
    return 0;
}