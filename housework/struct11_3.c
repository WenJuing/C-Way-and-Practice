// 输入40名学生信息（学号、姓名、3门课成绩）
// 输出成绩报表（学号、姓名、3门课成绩、平均分数）
// 输出平均分前5名的学生姓名和平均分
#include <stdio.h>
#include <windows.h>
#define N 5
typedef struct {
    int id;
    char name[10];
    float score[3];
    float avg;
} Stu;
void get_info(Stu * stu);   // 输入学生信息
void show_info(Stu * stu);   // 输出学生信息
void show_great(Stu * stu);   // 输出平均分前5的学生的信息
int main()
{
    Stu stu[N];
    get_info(stu);
    show_info(stu);
    show_great(stu);
    system("pause");
    return 0;
}
void get_info(Stu * stu)
{
    int i;
    printf("输入%d名学生的信息（学号/姓名/3门课分数）：", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %s %f %f %f", &stu[i].id, stu[i].name, 
        &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].avg = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3; // 计算平均分
    }

}
void show_info(Stu * stu)
{
    int i;
    printf("编号\t姓名\t课1\t课2\t课3\t平均分\n");
    for (i = 0; i < N; i++)
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", stu[i].id, stu[i].name, 
        stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avg);
}
void show_great(Stu * stu)
{
    Stu t;
    int i, j;
    // 按平均分从高到底排序
    for (i = 0; i < N; i++)
        for (j = i+1; j < N; j++)
            if (stu[i].avg < stu[j].avg)
            {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
    printf("编号\t姓名\t课1\t课2\t课3\t平均分\n");  // 输出平均分前3高的学生信息
    for (i = 0; i < 3; i++)
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", stu[i].id, stu[i].name, 
        stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avg);
}