// 计算以下表达式的值
#include <stdio.h>
#include <windows.h>

int main()
{
    int a=2, b=5, c=0;
    float x=1.2, y;
    a=(b=x)+x;
    printf("a=%d,b=%d,x=%.2f\n", a, b, x);
    a=2, b=5, c=0, x=1.2;
    y=(float)a+x;
    printf("a=%d,y=%.2f,x=%.2f\n", a, y, x);
    a=2, b=5, c=0, x=1.2;
    c=(a=8,b);
    printf("a=%d,b=%d,c=%d\n", a, b, c);
    a=2, b=5, c=0, x=1.2;
    y=a=b=c=x=7.2;
    printf("a=%d,b=%d,c=%d,x=%.2f,y=%.2f\n", a, b, c, x, y);
    system("pause");
    return 0;
}