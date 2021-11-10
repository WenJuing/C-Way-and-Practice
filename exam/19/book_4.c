#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#define N 4
typedef struct book {
    int num;
    char name[20];
    float price;
    int stock;
} Book;
void input(Book * pbook);   // 输入图书信息
int cmp_mul(const void* _a, const void* _b);   // 二级排序
void save(Book * pbook);    // 存入文件
void show(Book * pbook);
int main()
{
    Book book[N];
    input(book);
    save(book);
    show(book);
    qsort(book, N, sizeof(book[0]), cmp_mul);
    show(book);
    system("pause");
    return 0;
}
void input(Book * pbook)
{
    printf("输入%d本图书的信息（书号、书名、价格和库存）：\n", N);
    for (Book * p = pbook; p < pbook + N; p++)
        scanf("%d %s %f %d", &p->num, p->name, &p->price, &p->stock);
}
int cmp_mul(const void* _a, const void* _b)
{
    Book * a = (Book*)_a;
    Book * b = (Book*)_b;
    // 按书名升序，若书名相同，则按单价降序
    if (strcmp(a->name, b->name) != 0)
    {
        if (strcmp(a->name, b->name) > 0)
            return 1;
        else if (strcmp(a->name, b->name) < 0)
            return -1;
        else
            return 0;
    }
    else
    {
        if (a->price < b->price)
            return 1;
        else if (a->price > b->price)
            return -1;
        else
            return 0;
    }
}
void save(Book * pbook)
{
    FILE * fp = fopen("book_list.dat", "wb");
    for (int i = 0; i < N; i++)
        fwrite(pbook+i, sizeof(Book), 1, fp);
    fclose(fp);
}
void show(Book * pbook)
{
    printf("书号   书名     单价        库存\n");
    for (Book * p = pbook; p < pbook + N; p++)
        printf("%d    %s        %.2f RMB    %d本\n", p->num, p->name, p->price, p->stock);
}
