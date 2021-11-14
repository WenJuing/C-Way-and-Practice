// 统计a~z的个数，按个数降序，个数相同则字母顺序排序

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i, j, t, cout[26] = {0};
    char c, alpha[26];
    for (i = 'a'; i <= 'z'; i++)
        alpha[i - 'a'] = i;
    // 输入
    while ((c=getchar()) != '\n')
    {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') cout[c-'a']++;
    }
    // 排序
    for (i = 1; i < 26; i++)
        for (j = 1; j < 26; j++)
            if (cout[j] > cout[j-1])
            {
                t = cout[j], cout[j] = cout[j-1], cout[j-1] = t;
                c = alpha[j], alpha[j] = alpha[j-1], alpha[j-1] = c;
            }
    // 输出
    for (i = 0 ; i < 26; i++)
        printf("%c:%d\n", alpha[i], cout[i]);
    system("pause");
    return 0;
}