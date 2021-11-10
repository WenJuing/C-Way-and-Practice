#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define N 5
typedef struct recipe {
    int id;
    char name[20];
    float price;
    char state;     // 状态Y/N
    int sum;    // 库存
} Recipe;
void show();    // 显示文件信息
void order();   // 点菜
void del();     // 删除不需要的菜品
int main()
{
    int i = 1;
    Recipe recipe[N], * p;
    FILE * fp = fopen("cai.dat", "wb");

    printf("输入%d部菜的信息（菜名/价格/状态/库存）\n", N);
    for (p = recipe; p < recipe + 5; p++, i++)
    {
        scanf("%s %f %c %d", p->name, &p->price, &p->state, &p->sum);
        p->id = i;
        fwrite(p, sizeof(Recipe), 1, fp);
    }
    fclose(fp);
    // 调用区
    order();
    show();
    del();
    show();
    
    system("pause");
    return 0;
}
void order()
{
    int i = 0, j, table_id, id, sum, flag = 0;
    char ordername[10], ch, str_id[10];
    FILE * fp = fopen("cai.dat", "rb"), * fp2;
    // recipe代表菜品信息，order代表订单信息
    Recipe recipe[N], order[100];
    // 读取文件信息
    while (fread(recipe+i, sizeof(Recipe), 1, fp)) i++;
    fclose(fp);
    printf("【点菜】请输入桌子编号：");
    scanf("%d", &table_id);
    i = 0;
    while (!flag)
    {
        // 显示菜品信息
        printf("编号   菜名      价格    状态    库存\n");
        for (j = 0; j < N; j++)
        printf("%5d %8s %8.2f  %5c    %5d\n", recipe[j].id,recipe[j].name,recipe[j].price,
        recipe[j].state,recipe[j].sum);
        printf("请输入菜品编号及数量：");
        scanf("%d %d", &id, &sum);
        // 若不再供应或数量不足，则重新输入
        if (recipe[id-1].state == 'N')
            puts("该菜品已不再供应，请选择其他菜品");
        else if (recipe[id-1].sum < sum)
            puts("输入数量过多，请减小订购量");
        else
        {
            // 保存订单信息到数组，更新菜品信息
            order[i].id = id;
            strcpy(order[i].name, recipe[id-1].name);
            order[i].price = recipe[id-1].price;
            order[i].sum = sum;
            recipe[id-1].sum -= sum;
            i++;
            printf("点菜成功！是否继续点单（Y/N）：");
            getchar();  // 消除回车
            scanf("%c", &ch);
            if (ch == 'N' || ch == 'n') flag = 1;
        }
    }
    // 点菜结束，生成文件名
    itoa(table_id, str_id, 10);
    strcpy(ordername, str_id);
    strcat(ordername, ".dat");
    // 存储订单信息到文件
    fp2 = fopen(ordername, "w");
    fprintf(fp, "编号   菜名      价格   库存\n");
    for (j = 0; j < i; j++)
        fprintf(fp2, "%d    %s      %.2f  %d\n", order[j].id, order[j].name, order[j].price, order[j].sum);
    fclose(fp2);
}
void show()
{
    int i = 0;
    FILE * fp = fopen("cai.dat", "rb");
    Recipe recipe[N];
    printf("编号   菜名      价格    状态    库存\n");
    while (fread(recipe+i, sizeof(Recipe), 1, fp))
    {
        printf("%5d %8s %8.2f  %5c    %5d\n", recipe[i].id,recipe[i].name,recipe[i].price,
        recipe[i].state,recipe[i].sum);
        i++;
    }
    fclose(fp);
}
void del()
{
    int i = 0;
    FILE * fp = fopen("cai.dat", "rb");
    Recipe recipe[N], * p = recipe;
    // 读取文件信息
    fclose(fp);
    while (fread(recipe+i, sizeof(Recipe), 1, fp)) i++;
    // 遍历数组，寻找state为N的子成员并删除
    for (i = 0; i < N; i++)
        if (recipe[i].state == 'N')
            memset(recipe+i, 0, sizeof(Recipe));
    // 保存数据
    fp = fopen("cai.dat", "wb");
    while (p->id)
    {
        fwrite(p, sizeof(Recipe), 1, fp);
        p++;
    }
    fclose(fp);
}
