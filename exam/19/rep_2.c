#include <stdio.h>
#include <Windows.h>
#include <string.h>
int strrepl(char *s, char *r, char c);
int main()
{
    char str[] = "code(1.2)";
    char c;
    char r[] = "().";
    int n;
    printf("输入替换字符：");
    c = getchar();
    printf("[替换结果]\n");
    printf("原字符串：%s\n", str);
    n = strrepl(str, r, c);
    printf("新字符串：%s，共替换了%d个字符\n", str, n);
    system("pause");
    return 0;
}
int strrepl(char *s, char *r, char c)
{
    int n = 0;
    // 遍历主字符串
    for (char * ps = s; ps < s + strlen(s); ps++)
    {
        // 讲主字符串中的每个字符与r数组里的一一比较，相同则替换
        for (char * pr = r; pr < r + strlen(r); pr++)
        {
            if (*ps == *pr)
            {
                *ps = c;
                n++;
            }
        }
    }
    return n;
}