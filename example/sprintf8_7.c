// sprintf(字符指针，格式化字符串，表达式列表)
// 格式化写入str
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    int a = 5, b = 6;
    char str[20];
    sprintf(str, "%d+%d=%d", a, b, a+b);
    puts(str);  // 结果为：5+6=11
    system("pause");
    return 0;
}