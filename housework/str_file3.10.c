// 输入一个字符串，输出到文本，每个字符独占一行
#include <stdio.h>
#include <windows.h>

int main()
{
    FILE * fp = fopen("str_file3.10.txt", "w");
    char ch;
    while ((ch=getchar()) != '\n')
        fputc(ch, fp), fputc('\n', fp);
    system("pause");
    return 0;
}