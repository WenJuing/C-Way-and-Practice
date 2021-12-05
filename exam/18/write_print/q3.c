#include <stdio.h>
#include <windows.h>
int calc(int a, int n) {
    static int f = 1;
    if (n > 0) {
        f = f * n;
        printf("%d\n", n);
        calc(a, n-1);
    }
    return f;
}
int main()
{
    int a, n, f;
    printf("Enter two values:");
    scanf("%d %d", &a, &n);
    f = calc(a, n);
    printf("%d", f);
    system("pause");
    return 0;
}