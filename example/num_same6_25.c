// 输入一个不超过9位的无符号整数，判断该整数中是否存在重复的数字
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, t, n, flag = 0, count[10] = {0};
    printf("请输入一个正整数：");
    scanf("%d", &n);
    t = n;
    while (t)
    {
        count[t % 10]++;    // 取该整数的每一位，并统计频数
        t /= 10;
    }
    for (i = 0; i < 10; i++)
        if (count[i] > 1)
            flag = 1;
    if (flag)
        printf("整数%d存在相同的数字\n", n);
    else
        printf("整数%d没有相同的数字\n", n);
    system("pause");
    return 0;
}