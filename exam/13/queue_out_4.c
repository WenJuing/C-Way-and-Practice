#include <stdio.h>
#include <windows.h>
#define N 10
int main()
{
    int i, cout, cur = 0, a[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (i = 0; i < 10; i++)
    {
        for (cout = 0; cout < 2; cur++, cur %= 12)
        {
            if (a[cur] != 0) cout++;
            if (cout == 2) 
            {
                printf("%3d", a[cur]);
                a[cur] = 0;
            }
        }
    }
    printf("\n最后两人的编号为：");
    for (i = 0; i < 12; i++)
        if (a[i] != 0)
            printf("%3d", a[i]);
    printf("\n");
    system("pause");
    return 0;
}