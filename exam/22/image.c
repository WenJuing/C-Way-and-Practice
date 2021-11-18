// 打印图像专题
#include <stdio.h>
#include <windows.h>
#define S 30
void show_diamond(int n);
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
void pascal_triangle(); // 利用一维数组打印下图所示的杨辉三角形（Pascal triangle）
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10  5  1
void show_char_triangle();  // 输出字符三角形
// ABCDEFGHI
//  ABCDEFG
//   ABCDE
//    ABC
//     A
int main()
{
    show_char_triangle();
    system("pause");
    return 0;
}
void show_diamond(int n)
{
    int i, j, k;
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
}
void pascal_triangle()
{
    int a[7], i, j;
    a[1] = 1;       // 生成第1行，递推的基
    printf("%-4d\n", a[1]);
    for (i = 2; i <= 6; i++)
    {
        a[i] = 1;
        for (j = i-1; j >= 2; j--)
            a[j] = a[j] + a[j-1];
        for (j = 1; j <= i; j++)
            printf("%-4d", a[j]);
        printf("\n");
    }
}
void show_char_triangle()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        for (j = 0; j < S + 5 + i; j++)
            putchar(' ');
        for (k = 1; k <= 11-2*i; k++)
            putchar('A'+k-1);
        printf("\n");
    }
}