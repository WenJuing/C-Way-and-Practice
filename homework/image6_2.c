// 输出菱形，比如N=7时
/*
   A   
  BBB
 CCCCC
DDDDDDD
 EEEEE
  FFF
   G 
*/
#include <stdio.h>
#include <windows.h>

int main()
{
    int n, i, j, k;
    printf("输入一个奇数：");
    scanf("%d", &n);
    // 输出上三角
    for (i = 0; i < (n-1)/2; i++)
    {
        // 打印空格
        for (j = 0; j<(n-1)/2 -i; j++) putchar(' ');
        // 打印字符
        for (k=0; k < i*2+1; k++) putchar('A'+i);
        putchar('\n');
    }
    // 打印中间行
    for (j = 0; j < n; j++) putchar('A'+(n+1)/2 -1);
    putchar('\n');
    // 输出下三角
    for (i=0; i < (n-1)/2; i++)
    {
        // 打印空格
        for (j = 0; j < i+1; j++) putchar(' ');
        // 打印字符
        for (k=0; k < n-2-2*i; k++) putchar('A'+i+(n+1)/2);
        putchar('\n');
    }
    system("pause");
    return 0;
}