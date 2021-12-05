// 读取文本数字，升序排序后保存回文本
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main()
{
    int i, j, t, a[20];
    FILE * fp1, * fp2;
    if ((fp1 = fopen("numbers.txt", "r")) == NULL)
    {
        printf("打开文件失败！");
        exit(0);
    }
    fp2 = fopen("new.txt", "w");    // 新建备份文件
    i = 0;                          // 判断结束条件或为!=EOF
    while (fscanf(fp1, "%d", a + i) == 1)   // 读取文件内容并输出
    {
        printf("%3d", a[i]);
        i++;
    }
    printf("\n");
    for (i = 1; i < 20; i++)    // 用冒泡法从小到大排序
        for (j = 1; j < 20; j++)
            if (a[j-1] > a[j])
                {t=a[j-1],a[j-1]=a[j],a[j]=t;}
    for (i = 0; i < 20; i++)    // 输出并保存数据到文件
    {
        printf("%3d", a[i]);
        fprintf(fp2, "%d\n", a[i]);
    }
    printf("\n");
    fclose(fp1);
    fclose(fp2);
    remove("numbers.txt");  // 删除原文件
    rename("new.txt", "numbers.txt");
    system("pause");
    return 0;
}
