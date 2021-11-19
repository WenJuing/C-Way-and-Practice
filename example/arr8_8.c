// 利用二维数组打印杨辉三角形
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10  10 5  1
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, a[6][6];
    for (i = 0; i < 6; i++) // 把两侧赋值为1
        a[i][0] = a[i][i] = 1;
    for (i = 2; i < 6; i++)
        for (j = 1; j < i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    for (i = 0; i < 6; i++) // 打印
    {
        for (j = 0; j <= i; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}