// 输入若干行文本，将其中的小写字母转化成大写字母，并将输入文本存入文件
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main()
{
    char ch;
    FILE * fp;
    if ((fp=fopen("file12_3.txt", "w")) == NULL)
    {
        printf("打开文件失败!\n");
        exit(0);
    }
    while ((ch=getchar()) != EOF)
    {
        if (ch>='a' && ch<='z') ch -= 32;
        fputc(ch, fp);
    }
    fclose(fp);
    system("pause");
    return 0;
}