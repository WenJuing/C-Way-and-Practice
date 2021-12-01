// 将一个整数数组中存放的数据完全颠倒顺序
#include <stdio.h>
#include <windows.h>
int main()
{
    int data[7]={1,2,3,4,5,6,7}, temp, k, *ph, *pt;
    ph = data;
    pt = data+6;
    while (pt > ph)
    {
        temp = *ph;
        *ph = *pt;  // ②
        *pt = temp;
        ph++;
        pt--;
    }
    for (k = 0; k < 7; k++)
        printf("%3d", *(data+k));   // ③
    printf("\n");
    system("pause");
    return 0;
}