// 输入一个字符串，提取字符串中的数字，并输出全部数字及个数
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
int main()
{
    char str[81], last_is_char = 1, * p = str;
    int i, count = 0, num;
    printf("请输入一个字符串：");
    gets(str);
    while (*p)
    {
        if (!isdigit(*p))   // 若非数字
        {
            last_is_char = 1;
            p++;
        }
        else
        {
            if (last_is_char)   // 若上一个是非数字，则标志新数字的开始
            {
                last_is_char = 0;
                for (num = 0; isdigit(*p); p++) // 连续处理数字，直到不是数字时结束
                    num = num*10 + *p - '0';
                count++;
                printf("数字%d：%d\n", count, num);
            }
        }
    }
    system("pause");
    return 0;
}