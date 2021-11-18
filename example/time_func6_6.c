// 使用时间类的函数
#include <stdio.h>
#include <windows.h>
#include <time.h>
int main()
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1e5; i++);  // 需要计时的代码
    end = clock();
    printf("time=%f\n", (double)(end-start)/CLOCKS_PER_SEC);
    system("pause");
    return 0;
}