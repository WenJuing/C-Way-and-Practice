// 8个人123123报数，报到3退出，问最后一人的编号是多少
#include <stdio.h>
#include <windows.h>
int main()
{
    int i, cout, cur = 0, arr[8] = {1,2,3,4,5,6,7,8}, *p = arr;
    for (i = 0; i < 7; i++)
    {
        for (cout = 0; cout < 3; cur++, cur %= 8)
        {
            if (arr[cur] != 0) cout++;
            if (cout == 3) arr[cur] = 0;
        }
    }
    while (*p == 0) p++;
    printf("结果是%d\n", *p);
    system("pause");
    return 0;
}

