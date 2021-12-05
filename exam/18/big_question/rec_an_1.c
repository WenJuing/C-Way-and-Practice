// 计算an
#include <stdio.h>
#include <windows.h>
int fun(int n);
int main()
{
    printf("a%d=%d\n", 3, fun(3));
    system("pause");
    return 0;
}
int fun(int n)
{
    if (n <= 0)
        return 0;
    else if (n % 2 != 0)    // n为奇数
        return fun(n-1)*2 + 1;
    else
        return fun(n-1)*2 - 1;
}