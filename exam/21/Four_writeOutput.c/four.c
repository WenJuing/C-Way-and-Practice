#include <stdio.h>
#include <windows.h>
#include <math.h>
long fun(int n)
{
    static long int f = 0;
    // n%2 ? f+=n : f-=n;
    return f;
}
int main()
{
    int i;
    for (i = 1; i <= 5; i++)    
        printf("%ld\n", fun(i));
    system("pause");
    return 0;
}