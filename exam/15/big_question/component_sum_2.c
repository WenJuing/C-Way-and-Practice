// 输出2~1000所有的同构数，比如5->25，6->36，25->625
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int n, t, cube;
    for (n = 2; n <= 1000; n++) 
    {
        for (t=n, cube=n*n; t%10==cube%10 && t; t/=10, cube/=10);
        if (t == 0) printf("%d的平方是%d，是同构数\n", n, n*n);
    }
    system("pause");
    return 0;
}