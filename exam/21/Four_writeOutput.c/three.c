#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int i,j,count=0,tag[30]={0};
    for (i = 2; i < 30; i++)
    {
        if (!tag[i]) {
            printf("%5d", i);
            if (++count%5==0)
                printf("\n");
            for (j=2*i; j < 30; j+=i)
                tag[j]=1;
        }

    }
    system("pause");
    return 0;
}