#include <stdio.h>
#include <windows.h>
int main()
{
    char a[16] = "abdehknpsrtuwxy", c = 'k';
    int top = 0, bottom = 14, mid;
    while (top <= bottom)
    {
        mid = (top+bottom) / 2;
        if (a[mid] == c)
        {
            printf("字符%c的位置是%d\n", c, mid+1);
            break;
        }
        else if (c > a[mid])
            top = mid + 1;
        else
            bottom = mid - 1;
    }
    system("pause");
    return 0;
}