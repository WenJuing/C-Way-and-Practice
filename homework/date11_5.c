// 输入两个日期（年月日），计算相隔的天数
// 样本
// 输入：1999 2 16  2021 11 14
// 输出：8307
#include <stdio.h>
#include <windows.h>
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d);   // 计算两个日期相隔的天数
int main()
{
    int start_y, start_m, start_d, end_y, end_m, end_d;
    printf("输入开始日期（年/月/日）：");
    scanf("%d %d %d", &start_y, &start_m, &start_d);
    printf("输入结束日期（年/月/日）：");
    scanf("%d %d %d", &end_y, &end_m, &end_d);
    printf("相隔：%d天\n", diff(start_y,start_m,start_d,end_y,end_m,end_d));
    system("pause");
    return 0;
}
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d)
{
    int y1, m1, d1, y2, m2, d2;

    m1 = (start_m + 9) % 12;
    y1 = start_y - m1 / 10;
    d1 = y1*365 + y1/4 - y1/100 + y1/400 + (m1*306 + 5) / 10 + (start_d-1);
    
    m2 = (end_m + 9) % 12;
    y2 = end_y - m2 / 10;
    d2 = y2*365 + y2/4 - y2/100 + y2/400 + (m2*306 + 5) / 10 + (end_d-1);

    return d2 - d1;
}