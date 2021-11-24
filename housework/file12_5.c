// 统计文本文件中单词的个数
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    char str[100], filename[100], last_is_blank = 1, * p;
    FILE * fp;
    printf("请输入要统计单词的文件名：");
    scanf("%s", filename);
    if ((fp=fopen(filename, "r")) == NULL)
    {
        printf("打开文件失败!\n");
        exit(0);
    }
    while ((fgets(str, 100, fp)) != NULL)   // 一次读取文本的一行
    {
        p = str;
        last_is_blank = 1;  // 注意：新的一句首先设置标志是必要的
        while (*p)  // 统计每行的单词个数
        {
            if (*p == ' ')
                last_is_blank = 1;
            else
            {
                if (last_is_blank)  // 若当前字符不为空格且上一字符为空格，则代表新单词开始
                {
                    last_is_blank = 0;
                    count++;
                }
            }
            p++;
        }
    }
    fclose(fp);
    printf("文件%s所包含的单词个数：%d\n", filename, count);
    system("pause");
    return 0;
}