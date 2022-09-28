#include <stdio.h>        //问题：输入两个字符串，验证其中一个串是否为另一个串的子串。
#include <string.h>
#include <windows.h>
void mycmp(char s1[],char s2[]);    
int main ()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    mycmp(s1, s2);
    system("pause");
    return 0;
}
void mycmp(char s1[],char s2[])
{
    int count, index, len_s1, len_s2, flag = 0, t;
    char tmp[200];
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    if (len_s1 <= len_s2)         // 令s1始终是主串
    {
        strcpy(tmp, s1), t = len_s1;
        strcpy(s1, s2), len_s1 = len_s2;
        strcpy(s2, tmp), len_s2 = t;
    }
    for (int i=0; i<len_s1-len_s2; i++)
    {
        count = 0, index = i;
        for (s1[index] == s2[0]; s1[index]==s2[count] && count<len_s2; index++, count++);           // 开始匹配
        if(count==strlen(s2))
        {
            printf("(%s) is substring of (%s)\n",s2,s1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("No substring\n");
}