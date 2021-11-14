// 将磁盘中的一个文本文件逐行逆置到另一个文件中
#include <stdio.h>
#include <windows.h>
int main()
{
    int i = 0;
    char word[200][50];
    FILE * fp = fopen("file12_4.txt", "r");
    while (fgets(word[i++], 50, fp));
    fclose(fp);
    fp = fopen("file12_4_result.txt", "w");
    for (i = i-1; i >= 0; i--)
        fputs(word[i], fp);
    fclose(fp);
    system("pause");
    return 0;
}