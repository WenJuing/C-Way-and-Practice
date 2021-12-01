// 将十六进制转变为10进制
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char h[36];
    double d=0.0, p=1.0;
    int i=0, k=0, n=1;
    printf("\nPlease input hexadecimal data:\n");
    scanf("%s, h");
    strupr(h);
    while (h[i]==' ') i++;
    if (h[i] == '-') {n=-1;i++;}
    if (h[i]=='+') i++;
    while (h[i]!=0) {
        if (h[i] == '.') {k=1;i++;continue;}
        if (h[i] >= '0' && h[i] <= '9')
            h[i] = h[i] - 48;
        else if (h[i] >= 'A' && h[i] <= 'F')    // ④
            h[i] = h[i] - 55;
        else {
            printf("\nError!\n");
            break;
        }
        if (k == 0)
            d = d*16 + h[i];
        else {
            p = p/16.0;
            d += p * h[i];  // ⑤    未解决
        }
        i++;
    }
    d = d*n;
    printf("Decimal data is:%lf\n", d);
    system("pause");
    return 0;
}