// 指针的深入应用
#include <stdio.h>
#include <windows.h>
void point_to_point();  // 指向指针的指针
void point_to_arr();    // 指向行指针的指针
void point_to_point_arr();    // 指向指针的指针 数组
void point_to_func();   // 指向函数的指针

int get_max(int a, int b);
int main()
{
    point_to_func();
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
// **b[10]是** b的数组，每个成员都是一个指向指针的指针(指针指针)
void point_to_point_arr()
{
    char * a[10] = {"hello", "china", "!"}; // a的成员是地址
    char ** b[10];
    b[0] = a;   // 赋值：指针=地址 指针指针=地址地址
    b[1] = a+1;
    b[2] = a+2;
    for (int i = 0; i < 3; i++)
        printf("%s ", *b[i]);   // b[i]是指针, *b[i]才是地址
    printf("\n");
}
void point_to_func()
{
    int (*p)(int, int);
    p = get_max;
    printf("max is %d\n", p(11,22));    // 三种方法效果相同
    printf("max is %d\n", (*p)(11,22));
    printf("max is %d\n", get_max(11,22));
}
int get_max(int a, int b)
{
    return a > b ? a : b;
}