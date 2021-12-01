#include <stdio.h>
#include <Windows.h>
int main()
{
    int flag = 0;
    char str[80], sub[80], *p, *q, *t;
    printf("请输入主串：");
    scanf("%s", str);
    printf("请输入字串：");
    scanf("%s", sub);
    for (p = str; *p; p++)
    {
        t = p;
        for (q = sub; *q == *t; q++, t++);
        if (*q == '\0')
        {
            flag = 1;
            printf("出现的位置：%d\n", p - str + 1);
        }
    }
    if (!flag) printf("没有找到该字串\n");
    system("pause");
    return 0;
}