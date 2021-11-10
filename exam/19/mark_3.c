#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#define N 4
// 输出打卡次数最多的员工信息
typedef struct employee {
    char num[10];        // 工号
    char name[20];  // 姓名
    int count;      // 次数
} Employee;
void read(Employee * ep);   // 读取文件
void show(Employee * ep);   // 遍历输出
int cmp(const void* _a, const void* _b);
int main()
{
    Employee staff[N];
    read(staff);
    printf("工号    姓名    打卡次数：\n");
    for (Employee * p = staff; p < staff + N; p++)
        printf("%-8s%-8s  %d\n", p->num, p->name, p->count);
    qsort(staff, N, sizeof(staff[0]), cmp);
    show(staff);
    system("pause");
    return 0;
}
void read(Employee * ep)
{
    FILE * fp;
    if ((fp = fopen("daka.txt", "r+")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for (int i = 0; i < N; i++)
        fscanf(fp, "%s %s %d", ep[i].num, ep[i].name, &ep[i].count);
    fclose(fp);
}
void show(Employee * ep)
{
    int max = ep[0].count;
    printf("工号    姓名    打卡次数：\n");
    for (Employee * p = ep; p->count == max; p++)
        printf("%-8s%-8s  %d\n", p->num, p->name, p->count);
}
int cmp(const void* _a, const void* _b)
{
    // 按打卡次数降序排序
    Employee * a = (Employee*)_a;
    Employee * b = (Employee*)_b;
    if (a->count < b->count)
        return 1;
    else if (a->count > b->count)
        return -1;
    else
        return 0;
}