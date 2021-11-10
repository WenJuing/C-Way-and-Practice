#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
#define random(a, b) (rand()%(b-a+1)+a)
typedef struct {
    int id;
    char name[10];
} Stu;
int main()
{
    int num[5] = {1,2,3,4,5}, *p = num;
    for (int i = 0; i < 5; i++)
        putchar(num[i] + '0');
    putchar(10);
    p = p+1;
    for (int i = 0; i < 5; i++)
        putchar(num[i] + '0');
    putchar(10);
    system("pause");
    return 0;
}