// 判断一个字符串是否为空串，不是空串，输出内容，是空串，输出"你输入的是空串！"
#include <stdio.h>
#include <windows.h>
int main()
{
    int i = 0, blank = 0, len = 0;
    char str[50];
    gets(str);
    while (str[i])
    {
        if (str[i] == ' ')
            blank++;
        len++;
        i++;
    }
    if (blank == len)
        printf("你输入的是空串！\n");
    else
        puts(str);
    system("pause");
    return 0;
}