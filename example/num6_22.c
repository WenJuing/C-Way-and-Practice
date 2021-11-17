
#include <stdio.h>
#include <windows.h>
int main()
{
    int n, k = 2;
    printf("请输入一个大于或等于2的整数：");
    scanf("%d", &n);
    printf("质因子分解结果：%d=", n);
    while (1)
    {
        if (n % k == 0)
        {
            n /= k;
            if (n > 1)
                printf("%d*", k);
            else
            {
                printf("%d\n", k);  // 分解完毕
                break;
            }
        }
        else
            k++;
    }
    system("pause");
    return 0;
}