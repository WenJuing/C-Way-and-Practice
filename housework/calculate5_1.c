// 写出下列表达式的值
#include <stdio.h>
#include <windows.h>

int main()
{
    int b, c;
    printf("(1)%d\n", 4>9||3<40);
    printf("(2)%d\n", !(5>10));
    printf("(3)%d\n", 'x'>40);
    printf("(4)%d\n", 'x'+'y'>200);
    printf("(5)%d\n", !8>5);
    printf("(6)%d\n", 5&&8!=(5&&8));
    printf("(7)%d\n", 1==6>4);
    printf("(8)%d\n", (b=10)&&(c=0));
    printf("(9)%d\n", 5&&8);
    
    system("pause");
    return 0;
}