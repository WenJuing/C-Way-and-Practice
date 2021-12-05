#include <stdio.h>
#include <windows.h>
void func(char * s, char c) {
    char * p = s, * q = s;
    while (*q != '\0') {
        if (*q != c)
            *p++ = *q;
        q++;
    }
    *p = '\0';
}
int main()
{
    char str[30], ch;
    gets(str);
    ch = getchar();
    func(str, ch);
    printf("%s", str);
    system("pause");
    return 0;
}