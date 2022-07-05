#include <stdio.h>
#include <windows.h>
int getwords(char *str) {
    char words[100][50];
    int i=0, j=0,k=0;
    while(str[i]!='\0') {
        while (str[i]==' ') i++;
        while (str[i]!='\0' && str[i] !=' ')
            words[j][k++] = str[i++];   // ③
        words[j][k] = '\0';
        j++;
        k = 0;  // ④
    }
    k = j;
    for (j = k-1; j >= 0; j--)    // ⑤
        puts(words[j]);
    return k;
}
int main()
{
    char str[100];
    int tot;
    gets(str);
    tot = getwords(str);
    printf("一共有%d个单词\n", tot);
    system("pause");
    return 0;
}