#include <stdio.h>
#include <windows.h>
int count_holiday();    // 统计节假日天数
int main()
{
    printf("2022年有%d天节假日\n", count_holiday());
    system("pause");
    return 0;
}
int count_holiday()
{
    int n, count = 0;
    FILE * fp;
    if ((fp = fopen("holidays2022.txt", "r"))==0)
        printf("打开文件出错\n");
    while (fscanf(fp, "%*s %d", &n) != EOF)     // 使用*号跳过第一列
        if (n == 0)
            count++;
    return count;
}