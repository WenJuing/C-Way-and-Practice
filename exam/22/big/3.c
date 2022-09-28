#include <stdio.h>
#include <windows.h>
typedef struct {    // 保存学生信息
    int id;
    float height;
} Student;
void save();    // 保持学生数据
void show();    // 输出报表
int main()
{
    save();
    show();
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
void show()
{
    int i = 0, sum, height[25000], data[25000];   // 定义最高身高为2.5m
    Student stu;
    FILE * fp = fopen("data.txt", "rb");
    printf("\n身高\t人数\n");
    while (fread(&stu, sizeof(stu), 1, fp) == 1)
    {
        height[i] = stu.height * 100;    // 提取全部身高到数组
        i++;
    }
    fclose(fp);
    sum = i;    // 总人数
    for (i = 0; i < sum; i++)   // 统计
        data[height[i]]++;
    printf("---------------\n");
    for (i = 0; i < 25000; i++)
        if (data[i])
            printf("%.1f\t%d\n", i*1.0/100, data[i]);
    printf("---------------\n");
    printf("共%d人\n", sum);
}
