// 输入多行字符，统计输入的行数
#include <stdio.h>
#include <windows.h>

int main()
{
    int cout = 0;
    char str[50];

    // while (fgets(str, 50, stdin) != NULL)
    while (gets_s(str, 50) != NULL) // gets()相对不安全，无法控制溢出，因避免使用
        cout++;
    printf("行数：%d\n", cout);
    system("pause");
    return 0;
}