#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define random(a, b) (rand()%(b-a+1)+a)
// 2个5分、3个2分、5个1分，每次取5个，输出币值大于10，取1000次
int main()
{
    int i, five_coin, two_coin, one_coin, count = 0, sum;
    int kind;   // 1对应5分，2对应2分，3对应1分
    srand((unsigned)time(NULL));
    for (i = 0; i < 1000; i++)
    {
        five_coin = two_coin = one_coin = 0;
        while (five_coin + two_coin + one_coin < 5) // 取5枚硬币
        {
            kind = random(1, 3);
            if (kind == 1 && five_coin < 2) five_coin++; 
            if (kind == 2 && two_coin < 3) two_coin++; 
            if (kind == 3 && one_coin < 5) one_coin++; 
        }
        sum = five_coin*5 + two_coin*2 + one_coin*1;
        if (sum > 10)
        {
            printf("%d枚5分+%d枚2分+%d枚1分=%d分\n", five_coin, two_coin, one_coin, sum);
            count++;
        }
    }
    printf("经统计，在1000次取币里共有%d次币值大于10\n", count);
    system("pause");
    return 0;
}