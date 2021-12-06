#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char n[500], *p;
    int s, i, j;
    printf("\n输入一个不大于500位的正整数：\n");
    gets(n);
    printf("\n去除位数：\n");
    scanf("%d", &s);
    for (i = 0; i < s; i++) {
        for (p = n; *p; p++)
            if (*(p+1)<*p) break;
        strcpy(p, p+1);
    }
    i = 1;
    printf("\n结果是：\n");
    for (p = n; *p; p++,i++) {
        printf("%c", *p);
        if (i%5 == 0) printf(" ");
        if (i%20 == 0) printf("\n");
    }
    putchar('\n');
    system("pause");
    return 0;
}