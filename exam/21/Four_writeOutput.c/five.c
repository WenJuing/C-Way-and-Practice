#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int n,k,m,i,ii,j,a[10][10],b[10][10],ab[10][10];
    scanf("%d%d%d", &n,&k,&m);
    for (i = 0; i < n; i++)
        for (j = 0; j < k; j++)
            scanf("%d", a[i]+j);
    for (i = 0; i < k; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &b[i][0] + j);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            ab[i][j] = 0;
            for (ii = 0; ii < k; ii++)
                ab[i][j]=ab[i][j]+a[i][ii]*b[ii][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d", ab[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}