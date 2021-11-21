// 找到一个二维数组的鞍点（该行最大，该列最小）
#include <stdio.h>
#include <windows.h>

int main()
{
    int a[4][4] = {
        {1,2,3,4},
        {4,10,1,5},
        {0,1,2,3},  //  有一个鞍点，鞍点为a[2][3] = 3 
        {11,11,11,11}};
    int i, j, k, posti, postj, flag;
    for (i = 0; i < 4; i++)
    {
        flag = 1;
        for (j = 0; j < 4; j++)
        {
            posti = i, postj = 0;   // 默认值
            if (a[i][j] > a[posti][postj]) posti=i, postj=j; // 找到该行最大值的坐标
        }
        for (k = 0; k < 4; k++) // 与该列的其他值比较
            if (a[posti][postj] > a[k][postj])
                flag = 0;
        if (flag == 1)
            printf("鞍点为a[%d][%d]=%d\n", posti, postj, a[posti][postj]);
    }
    system("pause");
    return 0;
}