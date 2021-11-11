// 求所有水仙花数。
// 说明：水仙花数是一个3位数，其值位各位数3次方相加，比如：153=1^3+5^3+3^3
#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int i;
    for (i = 100; i < 1000; i++)
        if (pow((i%10),3)+pow((i/10)%10,3)+pow(i/100,3) == i)
            printf("%d\n", i);
    system("pause");
    return 0;
}