#include <stdio.h>
#include <windows.h>
#include <math.h>
void front_prime();  // 输出10000以内前任意n位都是质数的质数
int is_prime(int n);    // 判断是否是质数
int main()
{
    front_prime();
    system("pause");
    return 0;
}
void front_prime()
{
    int i, t;
    for (i = 2; i <= 10000; i++)
    {
        t = i;
        while (t)
        {
            if (is_prime(t))
                t /= 10;
            else
                break;
        }

        if (t == 0) printf("%d\n", i);
    }
}
int is_prime(int n)
{
    int i;
    for (i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}