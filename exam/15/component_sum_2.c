#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int i, t, square, flag;
    for (i = 2; i < 1000; i++)
    {
        t = i;
        square = i * i;
        flag = 1;
        while (t)
        {
            if (t % 10 != square % 10) flag = 0;
            t /= 10;
            square /= 10;
        }
        if (flag) printf("%d\n", i);
    }
    system("pause");
    return 0;
}