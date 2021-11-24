#include <stdio.h>
#include <windows.h>
#include <string.h>
void reverse_str(); // 将磁盘中的一个文本文件逐行逆置到另一个文件中
void count_from_file();  // 统计文本文件中单词的个数（重要）
void sort_word_from_file();   // 将两个文件的单词全部读取，并按字典顺序存入另一个文件
int main()
{
    system("pause");
    return 0;
}
void reverse_str()
{
    int i = 0;
    char word[200][50];
    FILE * fp = fopen("file12_4.txt", "r"); // 原始文件
    while (fgets(word[i++], 50, fp));
    fclose(fp);
    fp = fopen("file12_4_result.txt", "w");  // 转置后的文件
    for (i = i-1; i >= 0; i--)
        fputs(word[i], fp);
    fclose(fp);
}
void count_from_file()
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
}
void sort_word_from_file()
{
    int i = 0, j, count;    // count代表全部单词数量
    char word[200][50], tmp[50];
    FILE * fp_one, * fp_two, * fp_all;
    fp_one = fopen("file_one12_10.txt", "r");
    fp_two = fopen("file_two12_10.txt", "r");
    fp_all = fopen("file_all12_10.txt", "w");
    while (fgets(word[i], 50, fp_one) != NULL) i++;
    while (fgets(word[i], 50, fp_two) != NULL) i++;
    count = i;
    for (i = 0; i < count; i++)
        for (j = i; j < count; j++)
            if (strcmp(word[i], word[j]) > 0)   // 按a->z顺序排序
            {
                strcpy(tmp, word[i]);
                strcpy(word[i], word[j]);
                strcpy(word[j], tmp);
            }
    i = 0;
    for (i = 0; i < count; i++)
        fputs(word[i], fp_all);
    fclose(fp_one);
    fclose(fp_two);
    fclose(fp_all);
}