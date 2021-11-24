// 指针的深入应用
#include <stdio.h>
#include <windows.h>
void point_to_point();  // 指向指针的指针
void point_to_arr();    // 指向行指针的指针
int main()
{
    point_to_point();
    point_to_arr();
    system("pause");
    return 0;
}
// emo为指针数组，每个成员的值都是一个地址
// p是个指向指针的指针，它的值是地址
void point_to_point()
{
    int i;
    char * emo[5] = {"happy", "indifferent", "sad"}, ** p;
    p = emo;    
    for (i = 0; i < 3; i++)
    {
        printf("%s  ", *p); // 或者puts(*p)
        p++;
    }
    printf("\n");
}
// (*p)[3]首先是指针，然后是指向p[3]的指针，即指向行指针的指针
// (*p[3])[3]为行指针数组
void point_to_arr()
{
    int i, j;
    int a[3][3] = {{1,2,3},{11,12,13},{22,44,66}}, (*p)[3] = a;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%5d", *(*(p+i)+j));
        printf("\n");
    }
}
