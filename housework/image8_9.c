// 使用一维数组打印杨辉三角形
#include <stdio.h>
#include <windows.h>
//       1
//      1  1
//     1  2  1
//    1  3  3  1
//   1  4  6  4  1
// 1  5  10  10 5  1
int main()
{
    int i, j, k, n, a[81];
    printf("请输入行数：");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("%14d\n", 1);
        a[0] = a[1] = 1; // 始基
        for (i = 2; i < n; i++)
        {
            a[i] = 1;
            for (j=i-1; j > 0; j--)
                a[j] = a[j] + a[j-1];
            for (k=0; k < 10-i; k++)
                printf(" ");
            for (j = 0; j < i+1; j++)
                printf("%3d", a[j]);
            printf("\n");
        }
    }
    system("pause");
    return 0;
}