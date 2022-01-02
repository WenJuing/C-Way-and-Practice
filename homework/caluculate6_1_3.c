// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>

int main()
{
    char s1[] = "computing", s2[] = "computer";
    int i = 0;
    while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]) i++;
    printf("s1-s2=%d\n", s1[i]-s2[i]);
    system("pause");
    return 0;
}