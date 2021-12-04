#include <stdio.h>
#include <windows.h>
int main()
{
    char a[80], *p;
    int n, i, j;
    printf("\n输入一个不大于80位的正整数：\n");
    gets(a);
    printf("\n 去除位数：\n");
    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        for (p=a;*p;p++)
            if (*(p+1)>*p) break;
        strcpy(p,p+1);
    }
    printf("\n结果是：%s\n",a);
    system("pause");
    return 0;
}