// 写出下列表达式的值，并指出短路情况
#include <stdio.h>
#include <windows.h>

int main()
{
    int a;
    float f, x, y;
    f = 3.6, x = -1, y = 1.5;
    printf("(1)%d\n", x>y||(f/10)); // 0||0.36=1
    printf("(2)%d\n", x>0&&y>0||!x);    // 0&&短路||0=0
    printf("(3)%d\n", x++||x>y||x+y);   // 0||0||0.5=1
    printf("(4)%d\n", !0||y&&(a=x+2));  // 1||短路=1
    system("pause");
    return 0;
}