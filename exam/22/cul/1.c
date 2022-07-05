#include <stdio.h>
#include <windows.h>

int main()
{
    double a=0.2, b=1.8, c=0.6;
    int x=2, y=-1;
    printf("%d\n", ((c*c-4*a*b>0)?(x+=y):(y+=x)));
    a=0.2, b=1.8, c=0.6, x=2, y=-1;
    printf("%d\n", ((a+b+c)/x||('A'-'a')&&x+y*2));
    a=0.2, b=1.8, c=0.6, x=2, y=-1;    
    printf("%f\n", (x=(x,y=0.5,0.6)-y));
    a=0.2, b=1.8, c=0.6, x=2, y=-1;
    printf("%f\n", (a=b=x+y>0));
    system("pause");
    return 0;
}