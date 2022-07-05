#include <stdio.h>
#include <windows.h>
typedef struct {
    int id;
    float height;
} Student;
void save();    // 保持学生数据
void show();    // 输出报表
int main()
{


    system("pause");
    return 0;
}
void save()
{
    Student stu;
    FILE * fp = fopen("data.txt", "w+b");
    printf("请输入学号和身高（输入0结束）：\n");
    scanf("%d %f", &stu.id, &stu.height);
    while (stu.id!=0 && stu.height!=0)
    {
        fwrite(&stu, sizeof(stu), 1, fp);
        scanf("%d %f", &stu.id, &stu.height);
    }
    fclose(fp);
}
void show();    // 输出报表
