// 字符串的使用
// 1）轮换字符串。比如：abcde -> cdeab（向左轮换2次）
// 2）查找字串，并输出第一次出现的位置
// 3）
#include <stdio.h>
#include <windows.h>

void converse(char * str);  // 将每个字符向前转化4个位置。比如abz -> efd
void compare(char * s1, char * s2); // 比较两个字符串的大小，并输出差值
void invert_text();     // 将文本倒叙输出。示例：I love you -> you love I（重要）
void cout_word_one();   // 统计文本单词数量（方法1：利用数组）
void cout_word_two();   // 统计文本单词数量（方法2：利用状态标志变量）
void substr();          // 输入起始位置和长度，从主串截取字串
void subtract_num();    // 输入一个字符串，提取字符串中的数字，并输出全部数字及个数（重要）
int get_substr_pos(char * substr, char * str); // 输出字串在主串第一次出现的位置，若找不到字串，则返回0
int count_word(char * str);  // 统计单词个数（参数为字符串形式）
int longest_word(char * str);  // 输出最长单词，并返回其个数（重要）
int main()
{
    char str[20] = "azdwgtjqmn";
    char s1[] = "computing", s2[] = "computer";
    cout_word_one();
    system("pause");
    return 0;
}
void converse(char * str)
{
    char * p = str;
    int i, count = 0;
    for (i = 0; p[i]!='\0'; i++)
    {
        p[i] += 4;
        if (p[i] > 'z') p[i] -= 26;
        count++;
    }
    printf("str[%d]=%s\n", count, str);
}
void compare(char * s1, char * s2)
{
    int i = 0;
    while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]) i++;
    printf("s1-s2=%d\n", s1[i]-s2[i]);
}
void invert_text()
{
    int i;
    char word[81][81], ch;
    for (i = 0; i < 81; i++)
    {
        scanf("%s", word[i]);
        if ((ch=getchar()) == '\n') break;
    }
    while (word[i][0])
        printf("%s ", word[i--]);
    putchar(10);
}
void cout_word_one()
{
    int cout = 0;
    char ch, str[100];
    printf("输入文本：");
    while (1)
    {
        scanf("%s", str);   // 每次读一个字符串，遇到空格符结束
        cout++;
        if ((ch=getchar()) == '\n') break;  // 读取非字符串（空格和回车）
    }
    printf("单词统计：%d个\n", cout);
}
void cout_word_two()
{
    int count = 0, last_is_blank = 1;
    char c;
    printf("输入一行字符：\n");
    while ((c=getchar()) != '\n')   // 新单词开始的标志：上一个字符是空格且当前字符不是空格
    {
        if (c == ' ')
            last_is_blank = 1;
        else
        {
            if (last_is_blank)  // 若上一个字符是空格，则表示新单词开始
            {
                count++;
                last_is_blank = 0;
            }
        }
    }
    printf("单词统计：%d个\n", count);
}
// 输入一个字符串存到主串str，输入起始位置loc和长度len，截取字串存储到substr中
// 若截取长度不够，则就截取这么多
void substr()
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
}
void subtract_num()
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
}
int get_substr_pos(char * substr, char * str)
{
    int i, j, post;
    for (post = 0; str[post]; post++)
    {
        i = 0, j = post;
        while (substr[i] && substr[i]==str[j]) i++, j++;
        if (substr[i] == '\0')
            return post+1;
    }
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