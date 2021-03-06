#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
void sort_word_from_file();   // 将两个文件的单词全部读取，并按字典顺序存入另一个文件
int main()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            putchar('A' +(i+j)%9);
        putchar('\n');
    }

    system("pause");
    return 0;
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
