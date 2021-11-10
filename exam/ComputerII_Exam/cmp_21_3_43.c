#include <stdio.h>
#include <windows.h>
// 比较 a, b, c, d四个数字，将最大的存到a中，最小的存到d中
void cmp(int *a, int *b, int *c, int *d);
int main()
{
    int a, b, c, d;
    printf("输入四个整数：");
    while (~scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        printf("原顺序：a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
        cmp(&a, &b, &c, &d);
        printf("新顺序：a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
    }
    system("pause");
    return 0;
}
void cmp(int *a, int *b, int *c, int *d)
{
    int t;
    if (*a < *b)
    {
        t = *a;
        *a = *b;
        *b = t;
    }
    if (*a < *c)
    {
        t = *a;
        *a = *c;
        *c = t;
    }
    if (*a < *d)
    {
        t = *a;
        *a = *d;
        *d = t;
    }
    if (*b < *c)
    {
        t = *a;
        *a = *d;
        *d = t;
    }
    if (*a < *d)
    {
        t = *a;
        *a = *d;
        *d = t;
    }
    if (*b < *c)
    {
        t = *b;
        *b = *c;
        *c = t;
    }
}