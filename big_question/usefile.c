#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[10];
    char gender;
} Peoper;
void showlist(Peoper * p);  // 展示信息
void save1(Peoper * p);  // 存入到文本文件
void save2(Peoper * p);  // 存入到二进制文件
void read1(Peoper * p);  // 读取文本文件
void read2(Peoper * p);  // 读取二进制文件
int main()
{
    int i;
    // FILE * fp = fopen("comit.dat", "wb");
    Peoper peoper[6], * p;
    // printf("输入角色信息（id/name/gener）：\n");
    // for (p = peoper; p < peoper + 6; p++)
    // {
    //     scanf("%d %s %c", &p->id, p->name, &p->gender);
    //     fwrite(p, sizeof(Peoper), 1, fp);
        
    // }
    // fclose(fp);
    read1(peoper);
    system("pause");
    return 0;
}
void read1(Peoper * p)
{
    FILE * fp;
    Peoper peoper[6];
    if ((fp = fopen("comit.dat", "rb")) == NULL)
    {
        printf("ERROR!\n");
        exit(0);
    }
    printf("输出结果：\n");
    for (int i = 0; i < 6; i += 2)
    {
        fread(peoper + i, sizeof(Peoper), 1, fp);
        printf("%5d %8s %5c\n", peoper[i].id, peoper[i].name, peoper[i].gender);
        fseek(fp, sizeof(Peoper), 1);
    }
    putchar(10);
    fclose(fp);
}