#include <stdio.h>
#include <windows.h>
#define M 8
#define N 10
int main()
{
    char path[M*N];
    int p[M*N][2];
    int a[M][N]={{1,0,0,0,1,0,1,0},{1,1,1,1,0,1,1,1,1,1},
                 {0,1,0,1,0,1,0,0,1,0},{0,1,1,1,1,1,0,1,1,0},
                 {1,1,0,0,1,0,0,1,0,0,},{1,0,1,1,1,1,0,1,1,1},
                 {0,0,1,0,0,0,1,1,0,1},{0,1,1,1,1,1,1,0,0,1}};
    int i=0,j=0,k=0;
    path[k]=' ';
    p[0][0]=i;p[0][1]=j;
    while (i!=M-1||j!=N-1)
    {
        if (a[i+1][j]==1&&i<M&&path[k]!='U')
        {i++;k++;path[k]='D';}
        else if (a[i][j+1]==1&&j<N-1&&path[k]!='L')
        {j++;k++;path[k]='R';}
        else if (a[i-1][j]==1&&i>0&&path[k]!='D')
        {i--;k++;path[k]='U';}
        else if (a[i][j-1]==1&&j>0&&path[k]!='R')
        {j--;k++;path[k]='L';}
        else
            {a[i][j]=0;k--;i=p[k][0];j=p[k][1];continue;}
        p[k][0]=i;p[k][1]=j;
    }
    k++;
    path[k]='\0';
    printf("行走路线是：%s\n", path);
    system("pause");
    return 0;
}