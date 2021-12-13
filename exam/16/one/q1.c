#include <stdio.h>
#include <windows.h>
int f(int n) {
    if (n == 1)
        return 2;
    else
        return 2*n*f(n-1);
}
int main()
{
    printf("%d\n", f(3));
    system("pause");
    return 0;
}