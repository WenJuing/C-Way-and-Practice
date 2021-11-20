// sscanf(字符指针，格式化字符串，地址列表)
// 格式化读取str
#include <stdio.h>
#include <windows.h>
int main()
{
    int n;
    char str[10] = "12345", str2[]="ab12*ABCe123", sub[10];
    sscanf(str, "%d", &n);
    printf("%d\n", n);
    sscanf(str2, "%[1-9a-z]", sub); // 读取1-9，a-z的字串
    puts(sub);
    sscanf(str2, "%*[^A-Z]%s", sub); // 跳过不是A-Z的部分再读取（*表示跳过）
    puts(sub);

    // 读取sscanf8_7.txt文件中的姓名和成绩，并输出
    int score;
    char name[20], line[50];
    FILE * fp = fopen("sscanf8_7.txt", "r");
    printf("姓名\t成绩\n");
    while (fgets(line, 50, fp) != NULL)
    {
        sscanf(line, "%[^,], %d", name, &score);
        printf("%-10s%-5d\n", name, score);
    }
    fclose(fp);
    system("pause");
    return 0;
}