// 动态规划问题
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
// 问题1：有一组数字1 2 4 1 7 8 3，选择若干个数字，使之和最大，要求不能选连续的两个数字
// 思想：从最后一个开始选
// 记opt(i)为选择下标为i的数字，讨论opt(i)，有两种选择结果：
// 1）选择下标为i的数：opt(i)，则和为a[i]+opt(i-2)
// 2）不选择下标为i的数：opt(i-1)
// 选择和较大的一方，继续讨论opt(i-1)或opt(i-2)
// 直到opt(0)=a[0]=1，opt(1)=max(a[0],a[1])结束讨论
int rec_opt(int * a, int last_index);    // 递归实现，复杂度o(n*n)（last_index为最后一个有效元素的下标）
int dp_opt(int * a, int len); // 循环实现，复杂度o(n)（len为数组a的长度）
// 问题2：有一组数字3 34 4 12 5 2，选择若干个数字，判断有没有一种组合和为9
bool rec_subset(int * a, int i, int sum);   // 递归实现
int main()
{
    int a[7] = {1,2,4,1,7,8,3};
    int a2[6] = {3,34,4,12,5,2};
    // printf("最大的和为：%d\n", dp_opt(a, 7));
    rec_subset(a2, 6, 9) ? printf("true\n") : printf("false\n");
    system("pause");
    return 0;
}
int rec_opt(int * a, int i)
{
    if (i == 0)
        return a[0];
    else if (i == 1)
        return (a[0] > a[1] ? a[0] : a[1]); // 返回大的那个
    else
        return (rec_opt(a,i-2)+a[i]) > rec_opt(a,i-1) ? (rec_opt(a,i-2)+a[i]) : rec_opt(a,i-1);
}
int dp_opt(int * a, int len)
{
    int i;
    int * opt = (int*)malloc(sizeof(int)*len);   // 生成一个数组
    for (i = 0; i < len; i++) opt[i] = 0;  // 初始化
    opt[0] = a[0];
    opt[1] = a[0]>a[1] ? a[0] : a[1];
    for (i = 2; i < len; i++)
        opt[i] = (opt[i-2]+a[i])>opt[i-1] ? (opt[i-2]+a[i]) : opt[i-1];
    return opt[i-1];
}
bool rec_subset(int * a, int i, int sum)
{
    if (sum == 0)
        return true;
    else if (i == 0)
        return sum == a[0];
    else
    {
        return rec_subset(a, i-1, sum-a[i]);    // 未实现
        return rec_subset(a, i-1, sum);
    }
}