// 输入一个字符串存到主串str，输入起始位置loc和长度len，截取字串存储到substr中
// 若截取长度不够，则就截取这么多
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j = 0, loc, len;
    char str[81], substr[81];
    printf("请输入一个字符串：");
    gets(str);
    printf("开始截取字串，请输入起始位置和截取长度：");
    scanf("%d %d", &loc, &len);
    if (loc < 1 || loc > strlen(str) || len == 0)
        substr[0] = '\0';
    else 
    {
        for (i = loc - 1; j<len && str[i]!='\0'; i++, j++)
            substr[j] = str[i];
        substr[j] = '\0';
    }
    printf("主串：%s\n子串：%s\n", str, substr);
    system("pause");
    return 0;
}