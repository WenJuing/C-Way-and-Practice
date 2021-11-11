// 字符串的使用
// 1）轮换字符串。比如：abcde -> cdeab（向左轮换2次）
// 2）查找字串，并输出第一次出现的位置
// 3）
#include <stdio.h>
#include <windows.h>

void converse(char * str);  // 将每个字符向前轮换移动4个。比如abz -> efd
void compare(char * s1, char * s2); // 比较两个字符串的大小，并输出差值
void invert_text();     // 将文本倒叙输出。示例：I love you -> you love I
void cout_word();   // 统计文本单词数量
int main()
{
    char str[20] = "azdwgtjqmn";
    char s1[] = "computing", s2[] = "computer";
    cout_word();
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
void cout_word()
{
    int i, cout;
    char ch, list[100][20], str[1000];
    printf("输入文本：");
    for (i = 0; i < 100; i++)
    {
        scanf("%s", list[i]);
        cout++;
        if ((ch=getchar()) == '\n') break;
    }
    printf("单词统计：%d个\n", cout);
}
