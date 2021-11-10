#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int x,y=0;
    for (x=1;x<=30;)
    {
        if (x % 3==0)
        {
            y = y + 2 * x;
            x += 3;
        }
        else if (x % 5 ==0)
        {
            y = y + x -2;
            x += 5;
        }
        else if (x % 7 == 0)
        {
            y = y+x*x;
            x += 7;
        }
        else x++;
        printf("x=%d,y=%d\n",x,y);
    }
    system("pause");
    return 0;
}