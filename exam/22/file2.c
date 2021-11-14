#include <stdio.h>
#include <windows.h>
void reverse_str(); // 将磁盘中的一个文本文件逐行逆置到另一个文件中
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