// 5名学生4门课，放到socre[5][5]中，0行放学号，其他放成绩
// 1）输出所有不及格课程数 ≥ 2 的学生的学号
// 2）求第一门课全班平均分，返回结果并输出
// 3）找出平均分 ≥ 90，或全部成绩 ≥ 85的学生，输出他们的学号，成绩，平均成绩
// 4）排序后输出成绩表，排序规则：
// 一、按第一门课成绩降序，第一门成绩相同，按第二门成绩降序
// 二、第一、二门成绩都相同，按学号升序
#include <stdio.h>
#include <windows.h>
#include <string.h>
void find_bad_stu(float score[][5]);    // 问题一
float get_first_avg(float score[][5]);  // 问题二
void find_good_stu(float score[][5]);   // 问题三
void sort(float score[][5]);            // 问题四
void show(float score[][5]);    // 打印成绩表
int main()
{
    int i;
    float score[5][5] = {
        {10001, 85, 55, 50, 88},
        {10002, 85, 90, 88, 85},
        {10003, 53, 93, 100, 100},
        {10004, 92, 93, 93, 59},
        {10005, 85, 90, 100, 85}};

    show(score);
    find_bad_stu(score);
    printf("第一门课的成绩：%.2f\n", get_first_avg(score));
    find_good_stu(score);
    sort(score);
    system("pause");
    return 0;
}
void show(float score[][5])
{
    int i;
    printf("学号\t第一门\t第二门\t第三门\t第四门\n");
    for (i = 0; i < 5; i++)
        printf("%.f\t%.2f\t%.2f\t%.2f\t%.2f\n", score[i][0], score[i][1], 
        score[i][2], score[i][3], score[i][4]);
}
float get_first_avg(float score[][5])
{
    int i;
    float sum = 0;
    for (i = 0; i < 5; i++)
        sum += score[i][1];
    return sum / 5;
}
void find_bad_stu(float score[][5])
{
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 1; j < 5; j++)
            if (score[i][j] < 60)
                count++;
        if (count >= 2)
            printf("第%d位不及格的学生的学号为%.f\n", i+1, score[i][0]);
    }
}
void find_good_stu(float score[][5])
{
    int i, j, count;
    float sum;
    printf("学号\t第一门\t第二门\t第三门\t第四门\t平均成绩\n");
    for (i = 0; i < 5; i++)
    {
        count = sum = 0;
        for (j = 1; j < 5; j++)
        {
            if (score[i][j] >= 85)
            count++;
            sum += score[i][j];
        }
        if (count == 4 || sum/4 >= 90)
            printf("%.f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", score[i][0], score[i][1], 
        score[i][2], score[i][3], score[i][4], sum/4);
    }
}
void sort(float score[][5])
{
    int i, j;
    float t, pt[5];
    for (i = 1; i < 5; i++) // 使用冒泡排序确保排序完对应部分的学号升序
        for (j = 1; j < 5; j++)
        {
            if (score[j][1] != score[j-1][1])   // 第一门课成绩不同
            {
                if (score[j][1] > score[j-1][1]) // 第一门课降序排序
                {
                    memcpy(pt, score[j], sizeof(int)*5);
                    memcpy(score[j], score[j-1], sizeof(int)*5);
                    memcpy(score[j-1], pt, sizeof(int)*5);
                }
            }
            else
            {
                if (score[j][2] > score[j-1][2])    // 第二门课降序排序
                {
                    memcpy(pt, score[j], sizeof(int)*5);
                    memcpy(score[j], score[j-1], sizeof(int)*5);
                    memcpy(score[j-1], pt, sizeof(int)*5);
                }
            }
        }
    show(score);
}