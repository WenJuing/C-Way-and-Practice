// 将一数插入一升序数组中，使插入后仍为升序
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    int a[10]={1,3,5,7,9}, n, * p;
    scanf("%d", &n);
    p = a;
    while (*p)   // 定位到结束符
        p++;
    while (*(p-1)>n)    // 移动
    {
        *p = *(p-1);
        p--;
    }
    *p = n;
    for (p=a; *p; p++)
        printf("%d ", *p);
    printf("\n");
    system("pause");
    return 0;
}