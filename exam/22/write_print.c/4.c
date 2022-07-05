#include <stdio.h>
#include <windows.h>

int main()
{
    char str[100] = {'\0'};
    char res[100] = {'\0'};
    char temp[100] = {'\0'};
    scanf("%s", str);
    int length = strlen(str);
    int i = 0, j = 0, k = 0;
    int count = 0;
    do {
        if (i<length && str[i++]==str[j])
            count++;
        if (str[i]!=str[j]) {
            if (count <= 1)
                res[k++] = str[j];
            else {
                if (count > 1) {
                    res[k++] = '0'+count;
                    res[k++] = str[j];
                }
            }
            j = i;
            count = 0;
        }
    } while (i < length);
    res[k] = '\0';
    printf("The result is:%s\n", res);
    system("pause");
    return 0;
}