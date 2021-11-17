// 字符串的使用
// 1）轮换字符串。比如：abcde -> cdeab（向左轮换2次）
// 2）查找字串，并输出第一次出现的位置
// 3）
#include <stdio.h>
#include <windows.h>

void converse(char * str);  // 将每个字符向前轮换移动4个。比如abz -> efd
void compare(char * s1, char * s2); // 比较两个字符串的大小，并输出差值
void invert_text();     // 将文本倒叙输出。示例：I love you -> you love I
void cout_word_one();   // 统计文本单词数量（方法1：利用数组）
void cout_word_two();   // 统计文本单词数量（方法2：利用状态标志变量）
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