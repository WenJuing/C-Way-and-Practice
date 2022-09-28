#include <stdio.h>
#include <windows.h>
int fs(int a[][4]) {
    int t=0, i,j;
    for (i=0;i<4;i++){
        for (j=0;j<=i;j++)
            t+=a[i][j];
        printf("%d, ",t);
    }
    return(t);
}
int main()
{
    int a[][4]={5, 6, 7,8,16, 17, 18, 19,22, 23,24, 25, 31,32,33,34};
    printf("Sum=%d\n", fs(a)); 
    system("pause");
    return 0;
}