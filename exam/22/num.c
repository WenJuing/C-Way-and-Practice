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
void sum_an();          // 求2/1+3/2+5/3+8/5+...前20项和
void unique_num();      // 有0、1、2、3、4，能组成多少个互不相同且无重复数字的3位数？并输出这些3位数
void prime_factor();    // 将一个不小于2的整数分解质因数。例如 90 = 2 * 3 * 3 * 5
void sort_select();     // 对10个整数用 选择排序 进行降序排序并输出
void sort_bubble();     // 对10个整数用 冒泡排序 进行升序排序并输出
// 计算两个日期相隔的天数
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d); 
// 辅助函数**********************************************************
int Fibo(int n);// 求第n位斐波那契数列
void fun1();    // 方法1：直接求斐波那契数列的相关项，再直接算
void fun2();    // 方法2：找规律，再计算

int main()
{
    sum_an();
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
int Fibo(int n)
{
    if (n==2 || n==1)
        return 1;
    else return Fibo(n-1)+Fibo(n-2);
}
void fun1()
{
    int i;
    float sum = 0.0;
    for (i = 2; i <= 21; i++)
        sum += Fibo(i+1)*1.0 / Fibo(i);
    printf("方法一：前20项和为：%f\n", sum);
}
void fun2()
{
    // 设an = x/y，则an+1 = (x+y)/x
    int i, t;
    float x, y, sum = 0;
    x = 2, y = 1;
    for (i = 0; i < 20; i++)
    {
        sum += x / y;
        t = x;x = x + y; y = t;
    }
    printf("方法二：前20项和为：%f\n", sum);
}
void sum_an()
{
    fun1();
    fun2();
}
void unique_num()
{
    int i, j, k, count = 0;;
    for (i = 1; i <= 4; i++)
        for (j = 0; j <= 4; j++)
            for (k = 0; k <= 4; k++)
                if (i != j && i != k && j != k)
                {
                    printf("%d ", i*100+j*10+k);
                    count++;
                    if (count % 10 == 0) putchar('\n');
                }
    printf("\n共有%d个3位数\n", count);
}
void prime_factor()
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
}
void sort_select()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t, max_index;
    for (i = 0; i < 10; i++)
    {
        max_index = i;
        for (j = i; j < 10; j++)
        {
            if (a[j] > a[max_index])    // 找到最大的一个数的下标
            {
                max_index = j;
            }
        }
        if (a[max_index] != a[i])  // 若找到最大的数，则交换
        {
            t = a[i];
            a[i] = a[max_index];
            a[max_index] = t;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
}
void sort_bubble()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t;
    for (i = 1; i < 10; i++)
        for (j = 1; j < 10-i; j++)
            if (a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
}