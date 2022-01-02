// 输出字串在主串第一次出现的位置，若找不到字串，则返回0
#include <stdio.h>
#include <windows.h>
int get_substr_pos(char * substr, char * str);
int main()
{
    printf("%d\n", get_substr_pos("in", "china"));
    system("pause");
    return 0;
}
int get_substr_pos(char * substr, char * str)
{
    int i, j, post;
    for (post = 0; str[post]; post++)
    {
        i = 0, j = post;
        while (substr[i] && substr[i]==str[j]) i++, j++;
        if (substr[i] == '\0')
            return post+1;
    }
    return 0;
}