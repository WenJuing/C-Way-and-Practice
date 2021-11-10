#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#define N 3     // 股票个数

typedef struct stock {
    char name[20];  // 股票名字
    int code;       // 编码
    char market;    // 'H'或'S'
    float rate;     // 涨幅
} Stock;
void save_info(Stock * pStock);
void read_info(Stock *pStock);
int cmp_mul(const void* _a, const void* _b);
void show(Stock * S);
int main()
{
    Stock stock[N];
    printf("请输入%d支股票信息（股票名字、编码、市场H/S和涨幅）：\n", N);
    for (int i = 0; i < N; i++)
        scanf("%s %d %c %f", stock[i].name, &stock[i].code, &stock[i].market, &stock[i].rate);
    save_info(stock);
    show(stock);
    qsort(stock, N, sizeof(stock[0]), cmp_mul);
    show(stock);
    system("pause");
    return 0;
}

void save_info(Stock *pStock)
{
    FILE * fp;
    if ((fp = fopen("stock_info.dat", "wb")) == NULL)
        printf("打开失败！\n");
    for (Stock * p = pStock; p < pStock + N; p++)
        fwrite(p, sizeof(Stock), 1, fp);
    fclose(fp);
}
void read_info(Stock *pStock)
{
    FILE * fp = fopen("stock_info.dat", "rb");
    for (int i = 0; i < N; i++)
        fread(&pStock[i], sizeof(Stock), 1, fp);
    fclose(fp);
}
void show(Stock * S)
{
    printf("股票名字   编码   市场   涨幅：\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s        %d         %c      %.2f  \n", S[i].name, S[i].code, S[i].market, S[i].rate);
    }
}

int cmp_mul(const void* _a, const void* _b)
{
    Stock * a = (Stock*)_a;
    Stock * b = (Stock*)_b;
    // 按降幅降序，若涨幅相同，则按代码升序
    if (a->rate != b->rate)
    {
        if (a->rate < b->rate)
            return 1;
        else if (a->rate > b->rate)
            return -1;
        else
            return 0;
    }
    else
    {
        if (a->code > b->code)
            return 1;
        else if (a->code < b->code)
            return -1;
        else
            return 0;
    }
}