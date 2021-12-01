#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char string[80] = "bskyjfewmc", *p, *q, *r, ch;
    for (p = string; *p; p++)
    {
        for (q=r=p; *q; q++)
            if (*r > *q) r = q;
        if (*r != *p)
            ch = *r, *r = *p, *p = ch;
    }
    for (p = string; *p; p++)
    {
        for (q=p; *p==*q; q++);
        strcpy(p+1,q);
    }
    printf("结果是：%s\n", string);
    system("pause");
    return 0;
}