#include <stdio.h>
#include <windows.h>
int longest_word(char * str);  // 输出最长单词，并返回其个数
int count_word(char * str);  // 统计单词个数
int main()
{
    char str[81];
    printf("请输入一个字符串：");
    gets(str);
    // printf("累计%d个单词\n", count_word(str));
    printf("累计%d个\n", longest_word(str));
    system("pause");
    return 0;
}
int longest_word(char * str)
{
    int i = 0, j, max_len = 0, count = 0, last_is_blank = 1;
    char word[81][81];
    while (*str)
    {
        if (*str == ' ')
            last_is_blank = 1;
        else
        {
            if (last_is_blank)
            {
                last_is_blank = 0;
                for (j = 0; *str != ' ' && *str; j++, str++)    // 保存单词
                    word[i][j] = *str;
                i++;
                last_is_blank = 1;  // 结束说明是空格
                if (j > max_len) max_len = j;   // 获取最大单词长度
            }
        }
        str++;
    }
    // 输出最长的单词
    for (i = 0; word[i][0]; i++)
    {
        if (strlen(word[i]) == max_len)
        {
            puts(word[i]);
            count++;
        }
    }
    return count;
}
int count_word(char * str)
{
    int count = 0, last_is_blank = 1;
    while (*str)
    {
        if (*str == ' ')
            last_is_blank = 1;
        else
            if (last_is_blank)
                last_is_blank = 0, count++;
        str++;
    }
    return count;
}