#include <stdio.h>
#include <windows.h>
int main()
{
    int j=1, t=0;
    while (j<20) {
        j=j+1;
        if(j%3) continue;
        t += j;
    }
    printf("t=%d\n", t);
    system("pause");
    return 0;
}