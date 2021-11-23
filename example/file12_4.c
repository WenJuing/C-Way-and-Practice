// 运行exe，输入文件名，输出内容
#include <stdio.h>
#include <windows.h>
int main(int argc, char * argv[])
{
    char str[100];
    FILE * fp = fopen(argv[1], "r");
    while ((fgets(str, 100, fp)) != NULL)
        printf("%s", str);
    fclose(fp);
    system("pause");
    return 0;
}