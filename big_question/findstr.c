// 输入一主串和一字串，判断主串中是否含有字串，若有，则输出该字串在主串中的位置
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    int i, j, start, flag = 0, sign;
    char string[30], str[10];
    printf("输入主串：");
    gets(string);
    printf("输入字串：");
    gets(str);

    for (i = 0; i <= strlen(string) - strlen(str); i++)
    {
        start = i, sign = 1;
        for (j = 0; j < strlen(str); j++, start++)
        {
            if (string[start] != str[j])
            {
                sign = 0;
                break;
            }
        }
        if (sign == 1)
        {
            flag = 1;
            printf("字串位置：第%d个\n", i + 1);
        }
    }
    if (flag == 0) printf("没有找到该字串\n");
    system("pause");
    return 0;
}
