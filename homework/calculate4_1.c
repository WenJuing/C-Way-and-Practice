// 计算以下表达式的值
#include <stdio.h>
#include <windows.h>

int main()
{
    int i = 8, j = 3, k, a, b;
    unsigned long w = 5, u;
    double x = 1.42, y = 5.2, t, f;
    printf("(1)%d\n", k=i++);
    i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(2)%.2f\n", (int)x+0.4);
    i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    // printf("(3)%.2f\n", w+2=u);
    i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(4)%.2f\n", y+=x++);
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(5)%.2f\n", i/=j+12);
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(6)%d\n", k=--i);
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(7)%.2f\n", f=3/2*(t=30.0-10.0));
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(8)%d\n", k=(a=2,b=3,a+b));
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    // printf("(9)%.2f\n", ++(i+j));
        i = 8, j = 3, w = 5, x = 1.42, y = 5.2;
    printf("(10)%.2f\n", -2%3);
    system("pause");
    return 0;
}