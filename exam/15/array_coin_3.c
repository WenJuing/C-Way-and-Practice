#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define random(a, b) (rand()%(b-a+1)+a)
// 2个5分、3个2分、5个1分，每次取5个，输出币值大于10，取1000次
int main()
{
    int i, j, k, sum, n, count = 0, coin[10] = {5,5,2,2,2,1,1,1,1,1}, temp[10], array[3];
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < 10; j++) temp[j] = coin[j];
        for (j = 0; j < 3; j++) array[j] = 0;
        // 取5个币
        n = 10, sum = 0;
        while (n != 5)
        {
            srand((unsigned)time(NULL));
            k = random(1, 10);
            if (temp[k] != 0)
            {
                sum += temp[k];
                printf("取出%d分硬币，n=%d，i=%d\n", temp[k], n, i);
                if (temp[k] == 5) array[0]++;
                if (temp[k] == 2) array[1]++;
                if (temp[k] == 1) array[2]++;
                temp[k] = 0;
                n--;
            }
        }
        if (sum >= 10)
        {
            count++;
            printf("\n第%d次成功取出，总共取了%d次，取币情况：\n", count, i+1);
            if (array[0] != 0) printf("%d枚5分+", array[0]);
            if (array[1] != 0) printf("%d枚2分+", array[1]);
            if (array[2] != 0) printf("%d枚1分，", array[2]);
            printf("共%d分\n\n", sum);
        }  
    }
    system("pause");
    return 0;
}