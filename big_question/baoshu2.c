// N个人报数，每隔一人退出，问最后两名成员的号码为多少
#include <stdio.h>
#include <windows.h>
#define N 12
int main()
{
    int i, cout, cur = 0, arr[N], * p;
    // 给成员标记号码
    for (i = 0; i < N; i++)
        arr[i] = i + 1;
    for (i = 0; i < N - 2; i++)
    {
        for (cout = 0; cout < 2; cur++, cur %= N)
        {
            if (arr[cur] != 0) cout++;
            if (cout == 2) printf("%d ", arr[cur]), arr[cur] = 0;
        }
    }
    printf("\n剩余两名成员号码为：");
    for (p = arr; p < arr + N; p++)
        if (*p != 0) printf("%d ", *p);
    putchar('\n');
    system("pause");
    return 0;
}
