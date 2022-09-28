#include <stdio.h>
#include <windows.h>
#define N 3
int t=0;
int sub(int*s) {
   *s+=1;
   t+=*s;
   return t;
}
int main()
{
   int i,s=1;
   for (i=1;i<6;i++)s*=sub(&i);
   printf("结果是： %d \n",s);
    system("pause");
    return 0;
}