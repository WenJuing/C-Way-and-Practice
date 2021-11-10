// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>

int main()
{
    int x, a=1, b=1, c=1, d, y, z, m;
    x = (a=0) || (b=2) || (c=3);
    printf("%d %d %d %d\n", x, a, b, c);
    a=b=c=d=0;
    x = (a=1)||(b=2)&&(c=3)&&(d=4);
    printf("%d %d %d %d %d\n", x, a, b, c,d);
    
    m=3, x=2, y=4, z=1;
    m = (m<x) ? m : x++;
    m = (m<y) ? m : y++;
    m = (m<z) ? m : z++;
    printf("m=%d,x=%d,y=%d,z=%d\n",m,x,y,z);
    system("pause");
    return 0;
}