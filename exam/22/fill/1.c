#include <stdio.h>
#include <windows.h>
#define N 4
void shiftArr1Pos(int * arr1, int arrSize) {
    int i, temp;
    temp = arr1[0];
    for (i = 0; i < arrSize-1; i++)
        arr1[i] = arr1[i+1];
    arr1[i] = temp;     // ①
}
void arr1Rotatic(int * arr1, int arrSize, int rotFrom) {
    int i;
    for (i = 0;i < rotFrom;i++)
        shiftArr1Pos(arr1, arrSize);
}
int main()
{
    int i, arr1[] = {0,3,6,9,12,14,18,20,22,25,27};
    int ctr=sizeof(arr1)/sizeof(arr1[0]);
    arr1Rotatic(arr1, ctr, 4);  // ②
    for(i=0;i<ctr;i++)
        printf("%d ", arr1[i]);
    system("pause");
    return 0;
}