// 动态规划问题
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) a>b?a:b
// 问题1：有一组数字1 2 4 1 7 8 3，选择若干个数字，使之和最大，要求不能选连续的两个数字
// 思想：从最后一个开始选
// 记opt(i)为选择下标为i的数字，讨论opt(i)，有两种选择结果：
// 1）选择下标为i的数：opt(i)，则和为a[i]+opt(i-2)
// 2）不选择下标为i的数：opt(i-1)
// 选择和较大的一方，继续讨论opt(i-1)或opt(i-2)
// 直到opt(0)=a[0]=1，opt(1)=max(a[0],a[1])结束讨论
int rec_opt(int * a, int last_index);    // 递归实现，复杂度o(n*n)（last_index为最后一个有效元素的下标）
int dp_opt(int * a, int len); // 循环实现，复杂度o(n)（len为数组a的长度）
int main()
{
    int a[7] = {1,2,4,1,7,8,3};
    int a2[6] = {3,34,4,12,5,2};
	printf("%d\n", rec_subset(a2, 5, 9));
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
