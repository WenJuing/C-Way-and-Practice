#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, k, arr[] = {6, 9, 7, 10}, len, count=0;
    len = sizeof(arr) / sizeof(arr[0]); // 计算数组元素个数
    for (i = 0; i < len-2; i++)
        for (j = i+1; j < len-1; j++)
            for (k = j+1; k < len; k++)
                // 合格的三角形判定：两边之和大于第三边
                if (arr[i]+arr[j]>arr[k]&&arr[i]+arr[k]>arr[j]&&arr[j]+arr[k]>arr[i])
                {
                    count++;    // 统计三角形个数
                    printf("形成第%d个三角形，三边为%d %d %d\n", count, arr[i], arr[j], arr[k]);
                }
    system("pause");
    return 0;
}