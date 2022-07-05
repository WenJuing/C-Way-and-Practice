#include <stdio.h>
#include <windows.h>

int main()
{
    int arr1[10][10];
    int r1=3,c1=3;
    int i, j, yn=1;
    for (i = 0;i<r1;i++) {
        for(j=0;j<c1;j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (i=0;i<r1;i++) {
        for (j=0;j<c1;j++)
            printf("%2d", arr1[i][j]);
        printf("\n");
    }
    for (i =0;i<r1;i++){
        for (j=0;j<c1;j++) {
            if(arr1[i][j]!=1&&arr1[j][i]!=0){
                yn=0;
                break;
            }
        }
    }
    if(yn==1)
        printf("True.\n");
    else
        printf("False.\n");
    system("pause");
    return 0;
}