#include <stdio.h>
#include <windows.h>
#include <math.h>
void putstr(char * ch)
{
    if (*ch)
    {
        putchar(*ch);
        putstr(ch+1);
    }
}
int main()
{
    char ch[] = "goodforyou";
    putstr(ch);
    system("pause");
    return 0;
}