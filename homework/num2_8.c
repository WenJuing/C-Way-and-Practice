// 输入20个整数，统计正整数、负整数和0的个数，并分别计算前两部分的和及平均值
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, t, cnt1, cnt2, cnt3, sum1, sum2;
    cnt1 = cnt2 = cnt3 = sum1 = sum2 = 0;
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &t);
        if (t > 0) cnt1++, sum1 += t;
        else if (t < 0) cnt2++, sum2 += t;
        else cnt3++;
    }
    printf("正整数：共%d个，和为%d，平均值为%.2f\n", cnt1, sum1, sum1 * 1.0 / cnt1);
    printf("负整数：共%d个，和为%d，平均值为%.2f\n", cnt2, sum2, sum2 * 1.0 / cnt2);
    printf("零：共%d个\n", cnt3);
    system("pause");
    return 0;
}