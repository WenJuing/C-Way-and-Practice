// 通过递归算法求解Hanoi塔（汉诺塔）问题
#include <stdio.h>
#include <windows.h>
void hanoi(int n, char a, char b, char c);
int main()
{
    int n;
    char c1='a',c2='b',c3='c';
    scanf("%d", &n);
    hanoi(n, c1, c2, c3);
    system("pause");
    return 0;
}
void hanoi(int n, char a, char b, char c)
{
    if (n>0)    // 若无盘可移动，则终止移动
    {
        // 将n-1个盘从a借c移到b
        hanoi(n-1, a, c, b);
        // 将n号盘从a移到c
        printf("Move disc:%d from %c to %c\n", n, a, c);
        // 将n-1个盘从b借a移到c
        hanoi(n-1, b, a, c);
    }

}