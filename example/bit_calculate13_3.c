// 位运算
#include <stdio.h>
#include <windows.h>
void show_bin(unsigned char n); // 输出数的二进制形式
int main()
{
    unsigned char a = 135, b = 43;   // a的二进制：10000111，b的二进制：00101011
    printf("%3d的二进制形式：", a);
    show_bin(a);
    printf("%3d的二进制形式：", b);
    printf("与&、或|、非~、异或^的运算：\n");
    show_bin(b);
    printf("%d | %d = ", a, b); // |的运算规则：0|0=0、1|0=1、0|1=1、1|1=1
    show_bin(a|b);
    printf("%d & %d = ", a, b); // &的运算规则：0&0=0、1&0=0、0&1=0、1&1=1
    show_bin(a&b);
    printf("%d ^ %d = ", a, b); // ^的运算规则：0^0=0、1^0=1、0^1=1、1&=^1=0
    show_bin(a^b);
    printf("~%d = ", a); // ~的运算规则：0变成1、1变成0
    show_bin(~a);
    printf("左移<<和右移>>：\n");   // <<的运算规则：8bit的数在[0,128)内<<n代表乘2^n
    printf("%d << 1 = %d, %d >> 2 = %d\n", b, b<<1, a, a>>2);// >>n代表除2^n
    system("pause");
    return 0;
}
void show_bin(unsigned char n)
{
    // unsigned char * p = (unsigned char*)&n;
    for (int k = 7; k >= 0; k--)
    {
        if (n & (1 << k))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}