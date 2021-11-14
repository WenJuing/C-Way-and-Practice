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
// 计算两个日期相隔的天数
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d); 
int main()
{
    printf("相隔%d天\n", diff(1999,2,16,2021,11,14));
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
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d)
{
    int y1, m1, d1, y2, m2, d2;

    m1 = (start_m + 9) % 12;
    y1 = start_y - m1 / 10;
    d1 = y1*365 + y1/4 - y1/100 + y1/400 + (m1*306 + 5) / 10 + (start_d-1);
    
    m2 = (end_m + 9) % 12;
    y2 = end_y - m2 / 10;
    d2 = y2*365 + y2/4 - y2/100 + y2/400 + (m2*306 + 5) / 10 + (end_d-1);

    return d2 - d1;
}