// 输入3个点的坐标，判断它是否在一条直线上
#include <stdio.h>
#include <windows.h>

int main()
{
    int arr[6];
    float k1, k2;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", arr+i);
    }
    k1 = (arr[2]-arr[0])*1.0/(arr[3]-arr[1]);
    k2 = (arr[4]-arr[0])*1.0/(arr[5]-arr[1]);
    if (k1 == k2) printf("3点在一条直线上\n");
    else puts("不在一条直线上");
    system("pause");
    return 0;
}