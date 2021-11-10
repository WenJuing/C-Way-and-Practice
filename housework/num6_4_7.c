// 找到2 3 4 5位的所有Armstrong数
// Armstrong数：一个n位数等于其各位数的n次方之和
// 例如：153=1^3+5^3+3^3、1634=1^4+6^4+3^4+4^4
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int i, j, t, sum;
    for (i = 2; i <= 5; i++)    // 位数
    {
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
    putchar(10);
    system("pause");
    return 0;
}