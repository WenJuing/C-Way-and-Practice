#include <stdio.h>
#include <Windows.h>
#define N 3
typedef struct
{
    long int num;
    char name[15];
    int score[4];
} Student;
int main()
{
    Student stu[N];
    FILE * fp = fopen("student_17.dat", "wb");
    printf("输入%d位学生的信息（学号、姓名、4门课成绩[数学、英语、C语言、计算机原理]）：\n");
    for (Student * p = stu; p < stu + N; p++)
    {
        scanf("%d %s %d %d %d %d", &p->num, p->name, 
        &p->score[0], &p->score[1], &p->score[2], &p->score[3]);
        fwrite(p, sizeof(Student), 1, fp);
    }
    fclose(fp);
    system("pause");
    return 0;
}