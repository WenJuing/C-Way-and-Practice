#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
// 文件操作实践
// 某次LOL同人影响设计大赛，要求自创N名英雄
// 每名英雄包括：编号（从1自增）、姓名、性别（M或W）、单价等信息，编写函数完成一下功能：
// 1）输出所有英雄的信息（输出）
// 2）将英雄信息存入一个二进制文件中，文件名为"LoLHero+[英雄数量].dat"（存储到二进制文件）
// 3）从文件读取英雄信息，并按单价降序输出，若单价相同，则按编号升序输出（二级排序）
// 4）将3)中排序好的英雄信息存入一个文本文件中，文件名为"LoLHero+[英雄数量]+sorted.txt"（存储到文本文件）
// 5）读取排序好的文件信息，对英雄价格作一下调整（文件信息的更改、删除）
// 1、若价格>=10000，则将其改为8000
// 2、若5000<=价格<10000，将其改为6400
// 3、若2000<=价格<5000，将其改为2400
// 4、若500<=价格<2000，将其改为800
// 5、若价格<500或性别不是M/W，将其英雄信息删除
#define N 6
typedef struct hero {
    int id;
    char name[20];
    char gender;
    float price;
} HERO;
void show(HERO * p, int len);
void save_to_dat(HERO * p, int len);
void read_from_dat(HERO * p);
void sort(HERO * p);
void save_to_txt(HERO * p);
void read_from_txt(HERO * p);
void update(HERO * p);
int main()
{
    HERO hero[N], * p;
    int i;  // 编号
    // printf("输入%d名英雄的信息（姓名、性别、价格）：\n", N);
    // for (i = 1, p = hero; p < hero + N; p++, i++)
    // {
    //     p->id = i;
    //     scanf("%s %c %f", p->name, &p->gender, &p->price);
    // }
    // save_to_dat(hero, i-1);
    // read_from_dat(hero);
    // show(hero, N);
    // read_from_dat(hero);
    // sort(hero);
    // show(hero, N);
    // save_to_txt(hero);
    read_from_txt(hero);
    show(hero, N);
    update(hero);
    show(hero, N);
    system("pause");
    return 0;
}
void show(HERO * p, int len)
{
    puts("编号\t名称\t性别\t价格");
    for (int i = 0; i < len; i++, p++)
        printf("%d\t%s\t%c\t%.2f\n", p->id, p->name, p->gender, p->price);
}
void save_to_dat(HERO * p, int len)
{
    char filename[20] = "LoLHero", strnum[10];
    itoa(len, strnum, 10);
    strcat(filename, strnum);
    strcat(filename, ".dat");
    FILE * fp = fopen(filename, "wb");
    while (p->id)
    {
        fwrite(p, sizeof(HERO), 1, fp);
        p++;
    }
    fclose(fp);
}
void read_from_dat(HERO * p)
{
    FILE * fp = fopen("LOLHero6.dat", "rb");
    while (fread(p, sizeof(HERO), 1, fp)) p++;
    fclose(fp);
}
void sort(HERO * p)
{
    HERO t;
    int i, j;
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            if (p[j].price > p[j-1].price)
            {
                t = p[j];
                p[j] = p[j-1];
                p[j-1] = t;
            }
}
void save_to_txt(HERO * p)
{
    FILE * fp = fopen("LoLHero6sorted.txt", "w");
    for (int i = 0; i < N; i++)
        fprintf(fp, "%d\t%s\t%c\t%.2f\n", p[i].id, p[i].name, p[i].gender, p[i].price);
    fclose(fp);
}
void read_from_txt(HERO * p)
{
    FILE * fp = fopen("LOLHero6sorted.txt", "r");
    while (fscanf(fp, "%d %s %c %f", &p->id, p->name, &p->gender, &p->price) != EOF) p++;
    fclose(fp);
}
void update(HERO * p)
{
    HERO * pt = p;
    int i, len = N;
    FILE * fp;
    char filename[20] = "LoLHero", strnum[10];
    for (i = 0; i < N; i++, pt++)
    {
        if (pt->gender != 'W' && pt->gender != 'M' || pt->price < 500)
        {
            memset(pt, NULL, sizeof(HERO));
            len--;
        }
        else 
        {
            if (pt->price >= 10000) pt->price = 8000;
            else if (pt->price >= 5000) pt->price = 6400;
            else if (pt->price >= 2000) pt->price = 2400;
            else if (pt->price >= 500) pt->price = 800;
        }
    }
    // 将更新后的信息存入原文件
    itoa(len, strnum, 10);
    strcat(filename, strnum);
    strcat(filename, "update");
    strcat(filename, ".txt");
    fp = fopen(filename, "w");
    for (i = 0; i < len; i++)
        fprintf(fp, "%d\t%s\t%c\t%.2f\n", p[i].id, p[i].name, p[i].gender, p[i].price);
    fclose(fp);
}