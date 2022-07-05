#include <stdio.h>
#include <windows.h>

int main()
{
    int h1, m1, s1, h2, m2, s2, h3, m3, s3, tm, th;
    printf("请输入电影开始放映时间：");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("请输入电影时长：");
    scanf("%d %d %d", &h2, &m2, &s2);
    s3 = (s1 + s2) % 60;
    tm = (s1 + s2) / 60;
    m3 = (m1 + m2 + tm) % 60;
    th = (m1 + m2 + tm) / 60;
    h3 = (h1 + h2 + th) % 24;
    printf("电影结束时间：%d:%d:%d\n", h3, m3, s3);
    system("pause");
    return 0;
}