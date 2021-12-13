#include <stdio.h>
#include <windows.h>
int main()
{
    int fs(int a[][4]), a[][4]={5,16,27,38,16,17,28,39,22,23,24,35,31,32,33,34};
    printf("\nSum=%d\n", fs(a));
    system("pause");
    return 0;
}
int fs(int a[][4]) {
    int t=0,i,j,k;
    for (i=0;i<4;i++) {
        k=1;
        for (j=i;j>=0;j--) {
            t+=k*a[i][j];
            k=-k;
        }
        printf("%d,",t);
    }
    return t;
}