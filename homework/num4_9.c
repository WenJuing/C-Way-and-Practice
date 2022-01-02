// 逆向输出任意位数的数字。比如：163850->058261、65810347->74301856
#include <stdio.h>
#include <windows.h>
#include <string.h>
void func1();   // 方法一。利用字符串数组（输出前面可带0，12000->00021）
void func2();   // 方法二。数字转换（输出前面无0，12000->21）
int main()
{
    func2();
    system("pause");
    return 0;
}
void func1()
{
    char arr[20];
    puts("输入：");
    gets(arr);
    puts("输出");
    for (int i = strlen(arr) - 1; i >= 0; i--)
        putchar(arr[i]);
    putchar(10);
}
void func2()
{
    int num, t;
    scanf("%d", &num);
    t = num % 10;
    while (num / 10)
    {
        t *= 10;
        num /= 10;
        t += num % 10;
    }
    printf("%d\n", t);
}