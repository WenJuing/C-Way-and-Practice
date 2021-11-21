// 用折半查找法寻找要升序数组中要找的数
#include <stdio.h>
#include <windows.h>

int main()
{
    int i, n, low=0, high=9, mid, flag = 0,a[10]={1,2,3,5,7,12,14,22,25,44};
    for (i=0; i<10; i++) printf("%d  ", a[i]);
    printf("\n请输入一个要查找的数：");
    scanf("%d", &n);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (n == a[mid])
        {
            flag = 1;
            break;
        }
        else if (n < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    flag ? printf("数组中第%d个数是%d\n", mid+1, n) : printf("数组中没有%d这个数\n", n);
    system("pause");
    return 0;
}