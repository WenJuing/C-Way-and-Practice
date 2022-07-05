#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
bool is_prime(int n);       // 判断是否为质数
bool is_badnum(int n);      // 判断是否为丑陋数
int *find_badnum(int x);     // 找与x最近的丑陋数
int main()
{
    int i = 0, x, *badnum;
    printf("请输入一个整数：\n");
    scanf("%d", &x);
    badnum = find_badnum(x);
    printf("与%d最近的丑陋数是", x);
    for (i = 0; i < sizeof(badnum)/sizeof(badnum[0]) && badnum[i]!=0; i++)
        printf("%d ", badnum[i]);
    printf("\n");
    system("pause");
    return 0;
}
bool is_prime(int n)
{
    int i;
    for (i = 2; i <= n/2; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool is_badnum(int n)
{
    int i;
    for (i = 2; i <= n; i++)    // 因子包含本身
    {
        if (is_prime(i) && n%i==0)  // 是质因子
            if (i!=2 && i!=3 && i!= 5)
                return false;
            else
                continue;
    }
    return true;
}
int *find_badnum(int x)
{
    int i, left_badnum, right_badnum;
    static int res[2] = {0};
    if (x <= 1) 
    {
        res[0] = 1;
        return res;
    }
    if (is_badnum(x)) 
    {
        res[0] = x;
        return res;
    }
    // 找与x相邻的左边的一个丑陋数
    for (i = x-1; i >= 1; i--)
        if (is_badnum(i))
        {
            left_badnum = i;
            break;
        }
    // 找与x相邻的右边的一个丑陋数
    for (i = x+1;; i++)
        if (is_badnum(i))
        {
            right_badnum = i;
            break;
        }
    // 比较差值
    if (x-left_badnum < right_badnum-x)
        res[0] = left_badnum;
    else if (x-left_badnum > right_badnum-x)
        res[0] = right_badnum;
    else
        res[0]=left_badnum, res[1]=right_badnum;
    return res;
}
