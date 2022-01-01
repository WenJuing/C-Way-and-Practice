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
    int i, j, sum;
    char word[1000][20], temp[20];
    FILE * fp = fopen("test1.txt", "r");
    // 读取文本单词
    while (fscanf(fp, "%s", word + i) == 1) i++;
    fclose(fp);
    fp = fopen("test2.txt", "r");
    while (fscanf(fp, "%s", word + i) == 1) i++;
    fclose(fp);
    sum = i;
    // 排序
    for (i = 1; i < sum; i++)
        for (j = 1; j < sum; j++)
            if (strcmp(word[j-1], word[j]) > 0)
            {
                strcpy(temp, word[j]);
                strcpy(word[j], word[j-1]);
                strcpy(word[j-1], temp);
            }
    // 保存
    fp = fopen("test3.txt", "w");
    for (i = 0; i < sum; i++)
        fprintf(fp, "%s\n", word[i]);
    fclose(fp);
}