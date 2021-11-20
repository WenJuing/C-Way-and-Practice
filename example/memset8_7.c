// memset(p，int c，总字节)
#include <stdio.h>
#include <windows.h>
int main()
{
    int a[10] = {1,2,3,4,5,6}, b[10];
    memcpy(b, a, sizeof(int)*10);
    for (int i = 0; b[i]; i++)
        printf("%d  ", b[i]);
    printf("\n");
    memset(b, 0, sizeof(int)*10);   // 清空数组b
    for (int i = 0; b[i]; i++)
        printf("%d  ", b[i]);
    printf("\n");
    system("pause");
    return 0;
}