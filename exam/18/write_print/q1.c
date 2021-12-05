#include <stdio.h>
#include <windows.h>
int func(int x) {
    int a = 1, b = 1, t;
    if (x == 1) return 1;
    while (x > b) {
        t = b;
        b = a + b;
        a = t;
    }
    if (x == b)
        return 1;
    else
        return 0;
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", func(a));
    system("pause");
    return 0;
}