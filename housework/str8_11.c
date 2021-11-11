// 输入一行字符串，按单词倒序输出。比如：输入I love you  输出you love I
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, cout = 0;
    char ch, list[100][20];
    puts("输入一个字符串：");
    for (i = 0; i < 100; i++)
    {
        scanf("%s", list[i]);
        cout++;
        if((ch=getchar()) == '\n') break;
    }
    for (i = cout-1; i >= 0; i--)
        printf("%s ", list[i]);
    putchar(10);
    system("pause");
    return 0;
}