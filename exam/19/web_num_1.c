#include <stdio.h>
#include <Windows.h>
void find_web_num(int n);
int main()
{
    int n;
    printf("输入一个整数：\n");
    scanf("%d", &n);
    find_web_num(n);
    system("pause");
    return 0;
}
void find_web_num(int n)
{
    // 存全部约数
    int sum1 = 0, sum2 = 0;
    // 存数n的全部约束
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            sum1 += i;
            sum1 += n / i;
        }
    }
    sum1 /= 2;
    // 找一数，看是否能构成婚约数
    for (int i = 2; i < sum1; i++)
    {
        if (sum1 % i == 0)
        {
            sum2 += i;
            sum2 += sum1 / i;
        }
    }
    sum2 /= 2;
    if (sum2 == n)
        printf("%d与%d是一对婚约数\n", n, sum1);
    else
        printf("没有婚约数\n");
}