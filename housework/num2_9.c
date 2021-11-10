// 输入20个整数，找到最大正整数，最小正整数，最大负整数，最小负整数
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, n, max1, max2, min1, min2;
    scanf("%d", &n);
    if (n >= 0) max1 = min1 = n;
    else max2 = min2 = n;
    for (i = 0; i < 19; i++)
    {
        scanf("%d", &n);
        if (n >= 0)
        {
            if (n > max1) max1 = n;
            if (n < min1) min1 = n;
        }
        else
        {
            if (n > max2) max2 = n;
            if (n < min2) min2 = n;
        }
    }
    printf("最大正整数：%d，最大负整数：%d\n", max1, max2);
    printf("最小正整数：%d，最小负整数：%d\n", min1, min2);
    system("pause");
    return 0;
}