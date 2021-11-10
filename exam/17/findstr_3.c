#include <stdio.h>
#include <Windows.h>
int main()
{
    int n, i, j, flag = 0;
    char str[20], s[5];
    puts("输入字符串：");
    gets(str);
    puts("输入字串：");
    gets(s);
    for (i = 0; str[i]; i++)
    {
        n = i + 1;
        for (j = 0; s[j]; j++, i++)
        {
            if (str[i] == s[j]);
            else break;
        }
        if (j == strlen(s))
        {
            flag = 1;
            printf("在母串第%d个位置\n", n);
        }
    }
    if (flag == 0) puts("没有这样的字串\n"); 
    system("pause");
    return 0;
}