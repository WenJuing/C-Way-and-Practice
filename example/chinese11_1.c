// 处理含中文的字符串
#include <stdio.h>
#include <windows.h>
#include <wchar.h>  // 含有wchar_t类型的定义及相关函数
#include <locale.h> // 含有setlocale()
int main()
{
    setlocale(LC_ALL, "");  // 设置地区信息
    wchar_t wstr[100];
    puts("请输入姓名：");
    // fgetws(wstr, 100, stdin);
    wscanf(L"%ls", wstr);
    wprintf(L"%ls，你好！你的名字有%d个字\n", wstr, wcslen(wstr));
    system("pause");
    return 0;
}