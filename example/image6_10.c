#include <stdio.h>
#include <windows.h>
// 输出：
//ABCDEDFHI
// ABCDEFG
//  ABCDE
//   ABC
//    A
int main()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        // 打印空格
        for (j = 1; j <= i-1; j++) putchar(' ');
        // 打印字符
        for (k = 1; k <= 11-2*i; k++) putchar('A'+k-1);
        putchar('\n');
    }
    system("pause");
    return 0;
}