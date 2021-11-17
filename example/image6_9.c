#include <stdio.h>
#include <windows.h>
// 输出：
//     A
//    BBB
//   CCCCC
//  DDDDDDD
// EEEEEEEEE
int main()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        // 打印空格
        for (j = 1; j <= 5-i; j++) putchar(' ');
        // 打印字符
        for (k = 1; k <= i*2-1; k++) putchar('A'+i-1);
        putchar('\n');
    }
    system("pause");
    return 0;
}