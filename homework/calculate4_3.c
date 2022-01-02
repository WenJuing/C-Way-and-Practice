// 计算以下表达式的值
#include <stdio.h>
#include <windows.h>

int main()
{
    int a, b;
    float f = 3.6, x = -1, y = 1.5;
    printf("(1)%d\n", (a=b=4,a+1,b+1,a+b));
    printf("(2)%d\n", 30%6/2);
    printf("(3)%f\n", (int)f*100+0.5/100.0);
    printf("(4)%f\n", x+=y-=x);
    system("pause");
    return 0;
}