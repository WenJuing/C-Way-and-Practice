// 打印图像专题
#include <stdio.h>
#include <windows.h>
#include <string.h>
#define S 30
void show_diamond();
// 输出菱形，比如N=7时
/*
   A   
  BBB
 CCCCC
DDDDDDD
 EEEEE
  FFF
   G 
*/
void pascal_triangle_one(); // 利用一维数组打印下图所示的杨辉三角形（Pascal triangle）
void pascal_triangle2_random(); // 利用一维数组打印任意行杨辉三角形（Pascal triangle）
void pascal_triangle2_two(); // 利用二维数组打印下图所示的杨辉三角形（Pascal triangle）
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10  10 5  1
void show_char_triangle();  // 输出字符三角形
// ABCDEFGHI
//  ABCDEFG
//   ABCDE
//    ABC
//     A
void magical_square();  // 输入阶数，生成n阶魔方
// 比如，n=3时：
//   8  1  6
//   3  5  7
//   4  9  2
void show_image1();  // 输出下列图像
// INTERESTING
// NTERESTING
// TERESTING
// ERESTING
// RESTING
// ESTING
// STING
// TING
// ING
// NG
// G
int main()
{
    show_image1();
    system("pause");
    return 0;
}
void show_diamond()
{
    int i, j, k, n, B = 30, C = 1;  //  B控制空格个数，C控制符号个数
    printf("请输入行数：");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= B; j++)    // 输出空格
            putchar(' ');
        for (k = 1; k <= C; k++)    // 输出字符
            putchar('A' + i-1);
        if (i < (n+1)/2)
            B--, C += 2;
        else
            B++, C -= 2;
        putchar('\n'); 
    }
}
void pascal_triangle_one()
{
    int a[7], i, j;
    a[1] = 1;       // 生成第1行，递推的基
    printf("%-4d\n", a[1]);
    for (i = 2; i <= 6; i++)
    {
        a[i] = 1;
        for (j = i-1; j >= 2; j--)
            a[j] = a[j] + a[j-1];
        for (j = 1; j <= i; j++)
            printf("%-4d", a[j]);
        printf("\n");
    }
}
void pascal_triangle2_two()
{
    int i, j, a[6][6];
    for (i = 0; i < 6; i++) // 把两侧赋值为1
        a[i][0] = a[i][i] = 1;
    for (i = 2; i < 6; i++)
        for (j = 1; j < i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    for (i = 0; i < 6; i++) // 打印
    {
        for (j = 0; j <= i; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}
void show_char_triangle()
{
    int i, j, k;
    for (i = 1; i <= 5; i++)
    {
        for (j = 0; j < S + 5 + i; j++)
            putchar(' ');
        for (k = 1; k <= 11-2*i; k++)
            putchar('A'+k-1);
        printf("\n");
    }
}
void pascal_triangle2_random()
{
    int i, j, k, n, a[81];
    printf("请输入行数：");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("%14d\n", 1);
        a[0] = a[1] = 1; // 始基
        for (i = 2; i < n; i++)
        {
            a[i] = 1;
            for (j=i-1; j > 0; j--)
                a[j] = a[j] + a[j-1];
            for (k=0; k < 10-i; k++)
                printf(" ");
            for (j = 0; j < i+1; j++)
                printf("%3d", a[j]);
            printf("\n");
        }
    }
}
// 输入阶数，生成n阶魔方
// 定义：每行和、每列和、对角线和都为一常数即为魔方
// 生成规则：
// 1、把1放在第一行中间
// 2、每一放置数字，位置都是行一个数字的紧邻右上方（行减一，列加一）
// 3、若上一个数字在右上角，则这次的数字放在上一个数字的下面
// 4、若上一个数字在第一行，则这次的数字放最后行
// 5、若上一个数字在最后列，则这次的数字放第一列
// 6、若目标位置以被占，则这次的数字放上一个数字的下面
void magical_square()
{
    int i, j, k, n, a[20][20]={0};
    printf("输入奇阶数：");
    do {
        scanf("%d", &n);
    } while (!(n%2!=0 && n>=0 && n<=20));   // 检查n的输入
    a[0][(n-1)/2] = 1;  // 规则1
    i = 0, j = (n-1) / 2;   // 开始位置
    for (k = 2; k <= n*n; k++)
    {
        i -= 1, j += 1;     // 规则2
        if (i < 0 && j > n-1)   // 规则3
            i += 2, j -= 1;
        else if (i < 0) // 规则4
            i = n-1;
        else if (j > n-1)  // 规则5
            j = 0;
        if (a[i][j] != 0)   // 规则6
            i += 2, j -= 1;
        a[i][j] = k;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}
void show_image1()
{
    char str[100] = "INTERESTING", * p = str;
    while (*p)
    {
        puts(p);
        strcpy(p, p+1);
    }
}