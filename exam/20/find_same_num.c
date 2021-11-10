#include <stdio.h>
#include <Windows.h>

int main()
{
    int num1, t1, num2, t2, flag = 0, a[5], b[5];
    printf("输入两个不超过5位数的正整数：");
    scanf("%d %d", &num1, &num2);
    t1 = num1, t2 = num2;
    // 把num1的每位的数存入数组a
    for (int i = 0; t1 != 0; i++)
    {
        a[i] = t1 % 10;   // 取个位
        t1 /= 10; // 去个位
    }
    // 把num2的每位的数存入数组b
    for (int i = 0; t2 != 0; i++)
    {
        b[i] = t2 % 10;   // 取个位
        t2 /= 10; // 去个位
    }
    // 找数组a和数组b有无相同的数字
    for (int i = 0; a[i] != 0; i++)
    {
        for (int j = 0; b[j] != 0; j++)
        {
            if (a[i] == b[j])
            {
                printf("存在相同数字\n");
                flag = 1;
            }
        }
        if (flag == 1)  break;
    }
    if (flag == 0)
        printf("无相同数字\n");
    system("pause");
    return 0;
}