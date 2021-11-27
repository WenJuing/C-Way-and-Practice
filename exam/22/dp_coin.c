// 硬币找零问题：现有2元、5元、7元三种币值，求用最少的硬币个数凑出27元
#include <stdio.h>
#include <windows.h>
#define min(a, b) a>b?b:a
#define N 27    // 目标总额
//  arr[i]表示最少用arr[i]个硬币凑出i
// 计算方法：从a[0]=0开始，一次计算a[1]、a[2]...a[27]
// 计算公式：arr[i] = min{arr[i-2]+1, arr[i-5]+1, arr[i-7]+1}
// 无效值记1e5，即永远也凑不出目标总数额
int main()
{
    int i, arr[N+1];
    arr[0] = 0;
    for (i = 1; i <= N; i++)
    {
        if (i-2 < 0)    // 三个无效值
            arr[i] = 1e5;
        else if (i-5 < 0)   // arr[i-2]有效
            arr[i] = arr[i-2]+1;
        else if (i-7 < 0)   // arr[i-2]和arr[i-5]有效
            arr[i] = min(arr[i-2]+1, arr[i-5]+1);
        else 
            arr[i] = min(min(arr[i-2]+1,arr[i-5]+1), min(arr[i-2]+1,arr[i-7]+1));
    }
    printf("最少%d个硬币能凑出%d元\n", arr[N], 27);
    system("pause");
    return 0;
}

