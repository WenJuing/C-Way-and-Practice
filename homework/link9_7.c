// 有一个文本，每一行有一个数字，不知道有多少行
// 读写这个文本，把所有数字存入一个动态数组中（可以扩充位置）
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define BLOCK 20
typedef struct {
    int * array;
    int size;
} Array;
Array array_init(int size);   // 初始化数组
void array_free(Array * a);     // 释放数组内存
int * array_at(Array * a, int index);   // 访问成员
void inflate(Array * a, int add_size);    // 扩充内存
int main()
{
    int i, cout, number;
    FILE * fp = fopen("link9_7.txt", "r");
    Array a = array_init(10);
    // 从文件读取数据到数组
    cout = 0;
    while (fscanf(fp, "%d", &number) != EOF)
        *array_at(&a, cout++) = number;
    for (i = 0; i < cout; i++)
        printf("%d ", a.array[i]);
    array_free(&a);
    putchar(10);
    system("pause");
    return 0;
}
Array array_init(int size)
{
    Array a;
    a.array = (int*)malloc(sizeof(int)*size);
    a.size = size;
    return a;
}
int * array_at(Array * a, int index)
{
    // 若下标超过最大下标， 则扩充内存
    if (index >= a->size)
        inflate(a, (index/BLOCK+1)*BLOCK-a->size);
    return &(a->array[index]);
}
void inflate(Array * a, int add_size)
{
    // 定义一个新的指针，指向扩充好的更大的一块内存
    int * p = (int*)malloc(sizeof(int)*(a->size+add_size));
    // 将数据转移
    for (int i = 0; i < a->size; i++)
        p[i] = a->array[i];
    free(a->array);
    a->array = p;
    a->size += add_size;
}
void array_free(Array * a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}