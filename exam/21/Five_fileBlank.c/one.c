#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
int main()
{
    char str[30],t[30];
    int i;
    gets(str);
    strcpy(t, str);
    for (i = 0; str[i]!='\0';i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'Z' - (str[i]-'A');
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'z' - (str[i]-'a');
    }
    printf("origin is:%s\n", t);
    puts(str);
    system("pause");
    return 0;
}