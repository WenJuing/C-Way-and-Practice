#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int main ()
{
    char a;
    FILE * fp=fopen("upset.txt","w"); //fp指代upset
    char ch[10]="ijqhidh";
    fputs(ch, fp);   //往upset中写入
    fclose(fp);
    FILE * fp=fopen("upset.txt","r");
    FILE * fp1=fopen("happy.txt","w");     //fp1指代happy
    while((a=fgetc(fp))!=EOF)     //判断是否读取完毕
    {
        fputc(a,fp1);
        putchar(a);
    }
    fclose(fp);
    fclose(fp1);
    system("pause");
    return 0;
}
