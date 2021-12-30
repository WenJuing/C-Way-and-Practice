#include <stdio.h>
#include <windows.h>
#define K 5
#define N 10
int main()
{
    int i, j, t, arr[30], * p, cout[K] = {0};
    float len;  // 每个区间的长度
    printf("输入%d个整数：", N);
    for (p = arr; p < arr + N; p++)
        scanf("%d", p);
    // 对数组进行排序，以便找到最大值和最小值
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            if (arr[i] > arr[j])
                t = arr[i],arr[i] = arr[j],arr[j] = t;
    len = (arr[N-1] - arr[0]) * 1.0 / K;
    // 进行统计
    for (i = 0; i < N; i++)
        for (j = 0; j < K; j++)
            if(arr[i] >= arr[0]+len*j && arr[i] <= arr[0]+len*(j+1)) cout[j]++;
    // 输出结果
    for (j = 0; j < K; j++)
        printf("%.2f-%.2f:%d\n", arr[0]+len*j, arr[0]+len*(j+1), cout[j]);
    system("pause");
    return 0;
}