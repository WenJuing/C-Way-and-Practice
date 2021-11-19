// 输入一步运算的表达式(+-*/)，计算结果并输出
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
float evaluate(float left, char op, float right);
int main()
{
    float left, right;
    char op;
    printf("请输入一个算数表达式：");
    scanf("%f", &left);
    op = getchar();
    scanf("%f", &right);
    printf("结果为：%f\n", evaluate(left, op, right));
    system("pause");
    return 0;
}
float evaluate(float left, char op, float right)
{
    float res;
    if (op == '+') res = left+right;
    else if (op == '-') res = left-right;
    else if (op == '*') res = left*right;
    else if (op == '/')
    {
        if (right == 0)
        {
            printf("分母不能为0！\n");
            exit(1);
        }
        else
        {
            res = left / right;
        }
    }
    else
        printf("非法的输入！\n");
    return res;
}