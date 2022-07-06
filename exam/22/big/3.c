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
    int i = 0, sum;
    Student stu;
    int t, height[200] = {0};
    FILE * fp = fopen("data.txt", "rb");
    printf("\n身高\t人数\n");
    printf("---------------\n");
    while (fread(&stu, sizeof(stu), 1, fp) == 1)
    {
        t = stu.height;    // 提取全部身高
        height[t]++;
        printf("%.1f\n", height[i]);
        i++;
    }
    printf("---------------\n");
    fclose(fp);
    sum = i;
    printf("共%d人\n", sum);
}
