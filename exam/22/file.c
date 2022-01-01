// 对文件数据的增删改查
#include <stdio.h>
#include <windows.h>
#include <string.h>
#define LEN sizeof(student) // 一个学生结构体的长度
typedef struct {
    char name[20];
    char sex;   //  M/m：男生 F/f：女生
    int age;
    float score;
} student;
void file_write();  // 写入：向文件写入数据
void file_update(); // 修改：将成绩表所有女生成绩加5分
void file_delete(); // 删除：输入学生姓名，将该姓名的相关信息删除
void file_append(); // 追加：新追加一条学生数据
void file_insert(); // 插入：插入一条学生数据
void file_show();   // 输出：输出文件内容
int main()
{
    file_write();
    file_show();
    file_append();
    file_update();
    file_insert();
    system("pause");
    return 0;
}
void file_show()
{
    int len = 0;
    FILE * fp = fopen("file_update12_9.dat", "rb");
    student stu;
    printf("姓名\t性别\t年龄\t分数\n");
    while ((fread(&stu, LEN, 1, fp)) == 1)
    {
        printf("%s\t%c\t%d\t%.2f\n", stu.name, stu.sex, stu.age, stu.score);
        len++;
    }
    printf("学生总数：%d人\n", len);
    fclose(fp);
}
void file_update()
{
    student stu;
    FILE * fp = fopen("file_update12_9.dat", "r+b");    // r+b：可读可写，二进制方式打开
    while ((fread(&stu, LEN, 1, fp)) == 1)
    {
        if (stu.sex == 'F' || stu.sex == 'f')   // 若是女生
        {
            stu.score += 5;
            fseek(fp, -LEN, 1); // 将下移的指针返回原处
            fwrite(&stu, LEN, 1, fp);
            fseek(fp, 0, 1);    // 重要：fwrite()和fread()之间要重新定位
        }
    }
    fclose(fp);
}
void file_write()
{
    int i;
    FILE * fp = fopen("file_update12_9.dat", "wb");
    student stu;
    printf("姓名\t性别\t年龄\t分数\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%s %c %d %f", stu.name, &stu.sex, &stu.age, &stu.score);
        fwrite(&stu, LEN, 1, fp);
    }
    fclose(fp);
}
// 删除文件数据的思想：
// 新建一个临时文件，将需要的数据存入临时文件，再将原文件删除，最后将临时文件名改为原文件
void file_delete()
{
    char name[20];
    student stu;
    FILE * fp_new = fopen("tmp.dat", "wb");
    FILE * fp_old = fopen("file_update12_9.dat", "rb");
    printf("请输入要删除的学生姓名：");
    scanf("%s", name);
    while ((fread(&stu, LEN, 1, fp_old)) == 1)
        if (strcmp(stu.name, name) != 0)    // 若名字不同，则存入新文件中
            fwrite(&stu, LEN, 1, fp_new);
    fclose(fp_old);
    fclose(fp_new);
    remove("file_update12_9.dat");  // 删除原文件
    rename("tmp.dat", "file_update12_9.dat");   // 将临时文件名改为原文件名
}
void file_append()
{
    student stu;
    FILE * fp = fopen("file_update12_9.dat", "ab");
    printf("请输入一条新数据：");
    scanf("%s %c %d %f", stu.name, &stu.sex, &stu.age, &stu.score);
    fwrite(&stu, LEN, 1, fp);
    fclose(fp);
}
// 插入数据的思想与删除数据的思想大体一致：
// 将插入位置前的数据保存到临时文件，再接着保存要插入的数据
// 最后把插入位置之后的数据也保存到临时文件，删除原文件，把临时文件的名字改为原文件的名字
void file_insert()
{
    int i, pos, len = 0;    // pos为要插入的位置，从1开始算。len为文本的数据条数
    student stu;
    FILE * fp_new = fopen("tmp.dat", "wb");
    FILE * fp_old = fopen("file_update12_9.dat", "rb");
    while ((fread(&stu, LEN, 1, fp_old)) == 1) len++;   // 获取文本的数据条数（学生个数）
    rewind(fp_old);     // 将指针重新指向文件开头
    printf("请输入要插入的位置：");
    do {
        scanf("%d", &pos);
    } while (!(pos>=1&&pos<=len+1));    // 检查插入位置的合法性
    for (i = 0; i < pos-1; i++) // 保存插入位置前的所有数据
    {
        fread(&stu, LEN, 1, fp_old);
        fwrite(&stu, LEN, 1, fp_new);
    }
    printf("请输入一条新数据：");
    scanf("%s %c %d %f", stu.name, &stu.sex, &stu.age, &stu.score);
    fwrite(&stu, LEN, 1, fp_new);
    for (i = 0; i < len-pos+1; i++) // 保存插入位置后的所有数据
    {
        fread(&stu, LEN, 1, fp_old);
        fwrite(&stu, LEN, 1, fp_new);
    }
    fclose(fp_old);
    fclose(fp_new);
    remove("file_update12_9.dat");  // 删除原文件
    rename("tmp.dat", "file_update12_9.dat");   // 将临时文件名改为原文件名
}