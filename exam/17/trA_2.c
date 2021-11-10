#include <stdio.h>
#include <Windows.h>
int main()
{
    int a[4][4];
    int tr;
    printf("现生成一个4×4矩阵\n");
    for (int i = 0; i < 4; i++)
    {
        printf("请输入第%d行数据：", i + 1);
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    for (int i = 0; i < 4; i++)
    {
        tr += a[i][i];
        tr += a[i][3-i];
    }
    printf("%d\n", tr);
    system("pause");
    return 0;
}