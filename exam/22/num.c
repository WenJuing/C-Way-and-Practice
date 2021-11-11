// 数值计算类
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>
void Armstrong();       // 找到2 3 4 5位的所有[Armstrong数]
// 说明
// Armstrong数：一个n位数等于其各位数的n次方之和
// 例如：153=1^3+5^3+3^3、1634=1^4+6^4+3^4+4^4
int get_max_num(int n); // 求一个正整数的[最大素数因子]
void Narcissistic();    // 找到所有[水仙花数]
bool is_prime(int n);   // 判断是否是[素数]
int main()
{

    system("pause");
    return 0;
}
void Armstrong()
{
    int i, j, t, sum;
    for (i = 2; i <= 5; i++)    // 位数
        for (j = pow(10,i-1); j < pow(10,i)-1; j++)
        {
            sum = 0, t = j;
            while (t)
            {
                sum += pow(t%10, i);    // 取个加次方
                t /= 10;    // 取个
            }
            if (sum == j) printf("%d\n", j);
        }
}
bool is_prime(int n)
{
    int i;
    for (i = 2; i <= n/2; i++)
        if (n % i == 0) break;
    if (i > n/2) return true;
    else return false;
}
int get_max_num(int n)
{
    int i, max = 0;
    scanf("%d", &n);
    for (i = 2; i < n; i++) // 判断小于数本身的数（要求素数，i从2开始）
        if (n % i == 0 && is_prime(i)) max = i; // 是因子且是素数
    return max;
}
void Narcissistic()
{
    for (int i = 100; i < 1000; i++)
        if (pow((i%10),3)+pow((i/10)%10,3)+pow(i/100,3) == i)
            printf("%d\n", i);
}
