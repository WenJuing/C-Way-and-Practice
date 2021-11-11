#include <stdio.h>
#include <windows.h>
#include <time.h>   // 使用time()
#include <stdlib.h> // 使用rand()、srand()
void tou_touzi();   // 用伪随机数模拟投骰子，计算每一面出现的概率
int main()
{
    system("pause");
    return 0;
}
void tou_touzi()
{
    int i, m;
    int cout[6]={0};
    srand((unsigned)time(NULL));    // 设置种子
    for (i=0; i<1e5; i++)
        cout[rand()%6]++;   // 随机生成[0,5]的整数。生成[a,b]的公式：rand()%(b-a+1)+a
    printf("投掷%d次后统计的概率：\n", i);
    printf("第1面：%.2f\n", i*1.0 / cout[0]);
    printf("第2面：%.2f\n", i*1.0 / cout[1]);
    printf("第3面：%.2f\n", i*1.0 / cout[2]);
    printf("第4面：%.2f\n", i*1.0 / cout[3]);
    printf("第5面：%.2f\n", i*1.0 / cout[4]);
    printf("第6面：%.2f\n", i*1.0 / cout[5]);
}