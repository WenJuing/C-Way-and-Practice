// 测量文件的长度
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int filesize(FILE * fp);
int main(int argc, char * argv[])
{
    FILE * fp;
    char filename[20];
    printf("输入文件名：");
    scanf("%s", filename);
    if ((fp=fopen(filename, "rb")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    printf("文件%s的长度为%d\n", filename, filesize(fp));
    system("pause");
    return 0;
}
int filesize(FILE * fp)
{
    int cur_offset, len;
    cur_offset = ftell(fp); // 暂存当前指针位置
    fseek(fp, 0, 2);    // 将指针移动到文件尾部
    len = ftell(fp);    // 获取文件大小
    fseek(fp, cur_offset, 0);   // 回复文件指针的位置
    return len;
}