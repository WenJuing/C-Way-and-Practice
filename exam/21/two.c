#include <stdio.h>
#include <windows.h>

int main()
{
    double a=2.2,b=8.8,c=.6;
    int x=2,y=-1;
    printf("%f\n", b/a*(int)b/x);
    a=2.2,b=8.8,c=.6,x=2,y=-1;
    printf("%d\n", (a>=b/2) ? (x+=1):(y-=1));
    a=2.2,b=8.8,c=.6,x=2,y=-1;
    printf("%d\n", a||--x && ++y);
    a=2.2,b=8.8,c=.6,x=2,y=-1;
    printf("%f\n", (a=b,b=c,c=a));
    system("pause");
    return 0;
}