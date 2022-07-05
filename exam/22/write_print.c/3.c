#include <stdio.h>
#include <windows.h>
#define N 4
long conv(int a) {
    static long b = 0;
    int r;
    if(a!=0) {
        r = a%N;
        conv(a/N);
        b= b*10+r;
    }
    return b;
}
int main()
{
    long after;
    int before;
    printf("输入一个参数：");
    scanf("%d", &before);
    after = conv(before);
    printf("before:%d after:%d\n", before, after);
    system("pause");
    return 0;
}