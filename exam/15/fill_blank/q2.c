#include <stdio.h>
#include <windows.h>
int main()
{
    int i, j, a[10]={1,6,3,7,8,-1,-4,23,15}, b[10], t;
    for (i = 0; i < 10; i++)
    {
        t = 0;
        for (j = 0; j < 10; j++)
            if (a[j] < a[i]) t++;
        b[t] = a[i];
    }
    for (i = 0; i < 10; i++)
        printf("%3d", b[i]);
    printf("\n");
    system("pause");
    return 0;
}