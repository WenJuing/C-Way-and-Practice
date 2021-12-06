#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
#define random(a, b) (rand()%(b-a+1)+a)
void delete_random_char();  // 删除任意字符
void delete_limit_char();   // 删除指定字符
int check(char c);  // 指定字符
int main()
{
    delete_random_char();
    system("pause");
    return 0;
}
void delete_random_char()
{
    int i = 0;
    char str[100], del[100], *p1, *p2, *q;
    printf("请输入主串：");
    gets(str);
    printf("请输入要删除的字符：");
    gets(del);
    p2 = str;
    for (p1 = str; *p1; p1++)
        for (q = del; *q != *p1 && *q; q++);    // 遍历删除字符集
            if (*q == '\0') *p2++ = *p1;  // 若全部遍历完，则当前字符无需删除
    p2[i] = '\0'; // 形成字符串
    printf("结果为：%s\n", str);
}
void delete_limit_char()
{
    int i = 0;
    char str[100], t[100], *ps;
    printf("请输入主串：");
    gets(str);
    for (ps = str; *ps; ps++)
        if (check(*ps) == 0)
            t[i++] = *ps;
    t[i] = '\0';    // 形成字符串
    strcpy(str, t);
    printf("结果为：%s\n", str);
}
int check(char c)
{
    switch (c)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        case 'i':
        case 'I': 
            return 1;
        default :
            return 0;
    }
}