#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define N 5
typedef struct {
    int id;     // 方便辨识，可不加
    float s[4]; // 四门课的成绩
    int credit;     // 学分
    float avg;      // 平均成绩
} Student;
int cmp(const void*_a, const void*_b);  // 按学分降序，学分相同，则按均分降序
int main()
{
    int i, j, c[] = {5, 4, 4, 3};   // c代表每科的学分
    float sum;
    Student stu[N];
    printf("输入%d名学生的4门课的成绩：\n", N);
    for (i = 0; i < N; i++)
    {
        stu[i].id = i+1;
        stu[i].credit = sum = 0;
        for (j = 0; j < 4; j++)
        {
            scanf("%f", &stu[i].s[j]);
            sum += stu[i].s[j];
            if (stu[i].s[j] >= 60)  // 若及格，则加对应的学分
                stu[i].credit += c[j];
        }
        stu[i].avg = sum / 4;
    }
    
    printf("学生\t课程1\t课程2\t课程3\t课程4\t平均分\t学分\n");
    for (i = 0; i < N; i++)
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",
            stu[i].id,stu[i].s[0],stu[i].s[1],stu[i].s[2],stu[i].s[3],stu[i].avg,stu[i].credit);
    qsort(stu, N, sizeof(Student), cmp);    // 排序
    printf("学生\t课程1\t课程2\t课程3\t课程4\t平均分\t学分\n");
    for (i = 0; i < N; i++)
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",
            stu[i].id,stu[i].s[0],stu[i].s[1],stu[i].s[2],stu[i].s[3],stu[i].avg,stu[i].credit);
    system("pause");
    return 0;
}
int cmp(const void*_a, const void*_b)
{
    Student * a = (Student*)_a;
    Student * b = (Student*)_b;
    if (a->credit != b->credit) // 学分不同
    {
        if (a->credit < b->credit)  // 按学分降序
            return 1;
        else if (a->credit > b->credit)
            return -1;
        else
            return 0;
    }
    else    // 学分相同
    {
        if (a->avg < b->avg)    // 按平均分降序
            return 1;
        else if (a->avg > b->avg)
            return -1;
        else
            return 0;
    }
}
// 参考样本
// 99 11 22 33
// 77 77 77 77
// 66 77 88 99
// 12 34 88 88
// 99 99 33 33