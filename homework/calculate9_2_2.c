// 写出程序运行的结果
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, x=0;
    static int a[6]={1,2,3,4,5,6};
    for (i=0,j=1; i<5; ++i, j++)
        x+=a[i]*a[j];
        printf("%d\n",x);
    system("pause");
    return 0;
}
