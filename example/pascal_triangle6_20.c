#include <stdio.h>
#include <windows.h>
// 利用一维数组打印下图所示的杨辉三角形（Pascal triangle）
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10  5  1
int main()
{
    int a[7], i, j;
    a[1] = 1;   // 生成第1行，递推的基
    printf("%5d\n", a[1]);
    for (i = 2; i <= 6; i++)
    {
        a[i] = 1;
        for (j = i-1; j >= 2; j--)
            a[j] = a[j] + a[j-1];
        for (j = 1; j <= i; j++)
            printf("%5d", a[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}