// 写出下列表达式的值，并指出短路情况
#include <stdio.h>
#include <windows.h>

int main()
{
    int a, b, m=1, n=1;
    scanf("%d %d", &a, &b);
    if (a>0) m=m+n;
    if (a<b) n=2*m;
    else if (a==b) n=5;
    else n=m+n;
    printf("m=%d n=%d\n", m, n);
    system("pause");
    return 0;
}