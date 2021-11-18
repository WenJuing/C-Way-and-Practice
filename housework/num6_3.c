// 猴子吃桃问题
#include <stdio.h>
#include <windows.h>
void question1();  // 有n个桃，猴子每天吃一半加一个桃，第10天只剩一个桃，问原来有多少个桃？
void question2();  // 若逢奇数天多吃一个，逢偶数天多吃两个呢？
int main()
{
    question2();
    system("pause");
    return 0;
}
void question1()
{
    int i, x1, x2;
    x2 = 1;
    for (i = 0; i < 9; i++)
    {
        x1 = x2;
        x2 = 2 * (x1 + 1);
    }
    printf("原来有%d个桃\n", x2);
}
void question2()
{
    int i, x1, x2;
    x2 = 1;
    for (i = 1; i <= 9; i++)
    {
        x1 = x2;
        if (i % 2 != 0) x2 = 2 * (x1 + 1);  // 奇数天多吃1个
        else x2 = 2 * (x1 + 2);     // 偶数天多吃两个
    }
    printf("原来有%d个桃\n", x2);
}