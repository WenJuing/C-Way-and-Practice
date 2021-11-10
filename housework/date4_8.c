// 输入天数，将其转换为周数+天数。例如：17 -> 2周3天
// 输入一个字符串，输出到文本，每个字符独占一行
#include <stdio.h>
#include <windows.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("转换为%d周%d天\n", n / 7, n % 7);
    system("pause");
    return 0;
}