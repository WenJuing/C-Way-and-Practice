// 保存商品信息，并根据编号查找对应的商品
#include <stdio.h>
#include <windows.h>
#include <string.h>
typedef struct {    // 商品信息
    char id[10];
    char name[20];
    float price;
    int sum;
} Goods;
void save();    // 保存商品信息
void find();    // 寻找商品信息
void show();    // 打印商品信息
int main()
{
    // save();
    show();
    find();
    system("pause");
    return 0;
}
void save()
{
    Goods goods;
    FILE * fp = fopen("goods.dat", "wb");
    printf("请输入商品信息（编号/名称/价格/总量），按N结束：\n");
    while (1)
    {
        scanf("%s %s %f %d", goods.id, goods.name, &goods.price, &goods.sum);
        if (goods.id[0] == 'N' || goods.id[0] == 'n') break;
        fwrite(&goods, sizeof(Goods), 1, fp);
    }
    fclose(fp);
}
void find()
{
    int n, flag = 0;    // flag标志：是否找到商品
    char str_id[10];
    Goods goods;
    FILE * fp = fopen("Goods.dat", "rb");
    printf("请输入编号：");
    scanf("%d", &n);
    itoa(n, str_id, 10);    // 数字转字符串
    while (fread(&goods, sizeof(Goods), 1, fp) == 1)
    {
        if (strcmp(str_id, goods.id) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("%s\t%s\t%.2f\t%d\n", goods.id, goods.name, goods.price, goods.sum);
    else
        printf("抱歉，没有找到该商品~\n");
}
void show()
{
    Goods goods;
    FILE * fp = fopen("Goods.dat", "rb");
    printf("编号\t名称\t价格\t总量\n");
    while (fread(&goods, sizeof(Goods), 1, fp) == 1)
        printf("%s\t%s\t%.2f\t%d\n", goods.id, goods.name, goods.price, goods.sum);
}