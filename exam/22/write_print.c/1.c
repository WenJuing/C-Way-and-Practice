#include <stdio.h>
#include <windows.h>
#define N 5
int main()
{
    int a, b, c, d, i, num;
    printf("请输入第一个整数：");
    scanf("%d", &num);
    if (num > 0) {
        a = num; c=num;
    }
    else {
        b=num; d=num;
    }
    for (i=2; i<=N; i++) {
        printf("请输入第%d个整数：", i);
        scanf("%d", &num);
        if (num > 0) {
            if (num > a) a = num;
            else if (num < c) c=num;
        }
        else {
            if (num > b) b = num;
            else if (num < d) d = num;
        }
    }
    printf("最小正整数：%d\n, 最大正整数：%d\n, 最小负整数：%d\n，最大负整数：%d\n", c, a, d, b);
    system("pause");
    return 0;
}