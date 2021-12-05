#include <stdio.h>
#include <windows.h>
#include <string.h>
int cheek(char);
int main()
{
    char s[100], t[100];
    int i, j = 0;
    printf("Enter a string:\n");
    gets(s);
    for (i = 0; s[i]!='\0'; i++)
        if (cheek(s[i]) == 0)
            t[j++] = s[i];
    t[j] = '\0';
    strcpy(s, t);
    printf("%s\n", s);
    system("pause");
    return 0;
}
int cheek(char c) {
    switch(c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return 1;
        default:
            return 0;
    }
}