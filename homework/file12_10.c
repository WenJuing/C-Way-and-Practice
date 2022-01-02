// 将两个文件的单词全部读取，并按字典顺序存入另一个文件
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
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
    system("pause");
    return 0;
}