// 计算数组中元素的和以及平均值
#include <stdio.h>
#include <windows.h>
void avg_sum(int *, int, float *, int *);
int main()
{
    int a[10], i, sum;
    float avg;
    int *p = a;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    avg_sum(a, 10, &avg, &sum); // ③
    printf("avg=%f,sum=%d", avg, sum);
    system("pause");
    return 0;
}
void avg_sum(int a[], int n, float *pavg, int *psum)
{
    int i;
    *psum = 0;  // ④
    for (i = 0; i < n; i++) {
        *psum += a[i];  // ⑤
    }
    *pavg = *psum/n;
}