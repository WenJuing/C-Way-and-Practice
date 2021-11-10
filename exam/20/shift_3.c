#include <stdio.h>
#include <windows.h>
#include <string.h>

void shift(char * s, int n);
int main()
{
    char s[] = "abcde";
    puts(s);
    shift(s, 3);
    puts(s);
    system("pause");
    return 0;
}
void shift(char * s, int n)
{
    // 移动次数
    int i, j, num = n % strlen(s);
    char first;
    for (j = 0; j < num; j++)
    {
        first = s[0];
        for (i = 0; i < strlen(s) - 1; i++)
        {
            s[i] = s[i+1];
        }
        s[i] = first;
    }
}