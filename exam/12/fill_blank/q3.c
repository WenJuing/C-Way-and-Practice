#include <stdio.h>
#include <windows.h>
int fs(long p) {
    long m = p;
    int s = 0;
    do {
        s += m % 10;
    } while ((m=m/10) != 0);
    return s;
}
int main()
{
    long a[1000];
    int k, n, i, s1, s2;
    printf("Input a1、k、n：\n");
    scanf("%ld %d %d", &a[0], &k, &n);
    for (i = 1; i < n; i++) {
        s1 = fs(k*a[i-1]);
        a[i] = a[i-1];
        do {
            a[i] = a[i] + 1;
            s2 = fs(a[i]);  // ④
        } while (s1 != s2); // ⑤
    }
    for (i = 0; i < n; i++) {
        if (i%5 == 0) printf("\n");
        printf("%12ld", a[i]);
    }
    system("pause");
    return 0;
}