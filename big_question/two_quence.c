// 输入一串数字，统计0~9数字出现的次数，输出前3多的数字，输出格式：num:count
// 1、按次数降序排序
// 2、次数相同，按数字顺序升序排序
// 3、出现次数并列第3的一并输出
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, t, count[10] = {0}, number[10] = {0,1,2,3,4,5,6,7,8,9};
    char c;
    // 输入
    while ((c = getchar()) != '\n')
        if (c >= '0' && c <= '9') count[c-'0']++;
    // 按次数降序排序
    for (i = 1; i < 10; i++)
        for (j = 1; j < 10; j++)
        {
            if (count[j] > count[j-1])
            {
                t = count[j];
                count[j] = count[j-1];
                count[j-1] = t;

                t = number[j];
                number[j] = number[j-1];
                number[j-1] = t;
            }
        }
    printf("前3多的数字为：\n");
    for (i = 0; i < 3; i++)
        printf("%d:%d\n", number[i], count[i]);
    while (count[i] == count[2])
    {
        printf("%d:%d\n", number[i], count[i]);
        i++;
    }
    system("pause");
    return 0;
}