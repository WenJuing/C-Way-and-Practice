// 按步长截取字串
#include <stdio.h>
#include <windows.h>
void pick(char * s, char * sub, int beg, int end, int step);
int main()
{
    char s[100], sub[100];
    int beg, end, step;
    printf("请输入主串：");
    scanf("%s", s);
    printf("请输入起始位置、终止位置、步长：");
    scanf("%d %d %d", &beg, &end, &step);
    pick(s, sub, beg, end, step);
    puts(sub);
    system("pause");
    return 0;
}
void pick(char * s, char * sub, int beg, int end, int step)
{
    int i, j = 0;
    for (i = beg; i <= end-1; i+=step)
        sub[j++] = s[i];
    sub[j] = '\0';  // 形成字符串
}