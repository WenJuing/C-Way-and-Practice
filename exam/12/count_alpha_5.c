#include <stdio.h>
#include <Windows.h>
#include <string.h>
typedef struct {
    char c;
    int count;
} Alpha;
int cmp(const void* _a, const void* _b);
int main()
{
    int i, j;
    char ch;
    Alpha alpha[26];
    for (i = 97, j = 0; i <= 122; i++, j++)
    {
        alpha[j].c = i;
        alpha[j].count = 0;
    }
    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        for (int i = 0; i < 26; i++)
            if (ch == alpha[i].c) alpha[i].count++;
    }
    qsort(alpha, 26, sizeof(alpha[0]), cmp);
    for (i = 0; i < 10; i++)
    {
        printf("%c:%d\n", alpha[i].c, alpha[i].count);
    }
    for (i = 10; i < 26; i++)
        if (alpha[i].count == alpha[9].count)
            printf("%c:%d\n", alpha[i].c, alpha[i].count);

    system("pause");
    return 0;
}
int cmp(const void* _a, const void* _b)
{
    Alpha * a = (Alpha *)_a;
    Alpha * b = (Alpha *)_b;
    if (a->count != b->count)
    {
        if (a->count < b->count)
            return 1;
        else if (a->count > b->count)
            return -1;
        else return 0;
    }
    else
    {
        if (a->c > b->c)
            return 1;
        else if (a->c < b->c)
            return -1;
        else return 0;
    }

}