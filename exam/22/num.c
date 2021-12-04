// 数值计算类
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>
void Armstrong();       // 找到2 3 4 5位的所有[Armstrong数]
// 说明
// Armstrong数：一个n位数等于其各位数的n次方之和
// 例如：153=1^3+5^3+3^3、1634=1^4+6^4+3^4+4^4

int get_max_num(int n); // 求一个正整数的[最大素数因子]

void Narcissistic();    // 找到所有[水仙花数]

bool is_prime(int n);   // 判断是否是[素数]

void sum_an();          // 求2/1+3/2+5/3+8/5+...前20项和

void unique_num();      // 有0、1、2、3、4，能组成多少个互不相同且无重复数字的3位数？并输出这些3位数

void prime_factor();    // 将一个不小于2的整数分解质因数。例如 90 = 2 * 3 * 3 * 5

void sort_select();     // 对10个整数用 选择排序 进行降序排序并输出

void sort_bubble();     // 对10个整数用 冒泡排序 进行升序排序并输出

void same_number();     // 输入一个不超过9位的无符号整数，判断该整数中是否存在重复的数字

void sample_calculation(); // 输入表达式（只包含+-两种运算符），计算结果并输出

void insert_arr();      // 将一数插入一升序数组中，使插入后仍为升序

void fine_a_an_dian();  // 找到一个二维数组的鞍点（该行最大，该列最小）

void binary_search();   // 用折半查找法寻找要升序数组中要找的数

void bao_shu();         // （约瑟夫环）8个人围成一圈，从第一个人开始报数（从1到3报数），
                        // 凡报到3的人退出圈子，问最后留下的原来第几号

char buffer[80];
char * int_to_hex(int n);   // 十进制转十六进制

// 计算两个日期相隔的天数
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d); 

// 辅助函数**********************************************************
int Fibo(int n);// 求第n位斐波那契数列

void fun1();    // 方法1：直接求斐波那契数列的相关项，再直接算
void fun2();    // 方法2：找规律，再计算

float evaluate(float left, char op, float right);   // 进行四则运算

int main()
{
    bao_shu();
    system("pause");
    return 0;
}
void Armstrong()
{
    int i, j, t, sum;
    for (i = 2; i <= 5; i++)    // 位数
        for (j = pow(10,i-1); j < pow(10,i)-1; j++)
        {
            sum = 0, t = j;
            while (t)
            {
                sum += pow(t%10, i);    // 取个加次方
                t /= 10;    // 取个
            }
            if (sum == j) printf("%d\n", j);
        }
}
bool is_prime(int n)
{
    int i;
    for (i = 2; i <= n/2; i++)
        if (n % i == 0) break;
    if (i > n/2) return true;
    else return false;
}
int get_max_num(int n)
{
    int i, max = 0;
    scanf("%d", &n);
    for (i = 2; i < n; i++) // 判断小于数本身的数（要求素数，i从2开始）
        if (n % i == 0 && is_prime(i)) max = i; // 是因子且是素数
    return max;
}
void Narcissistic()
{
    for (int i = 100; i < 1000; i++)
        if (pow((i%10),3)+pow((i/10)%10,3)+pow(i/100,3) == i)
            printf("%d\n", i);
}
int diff(int start_y, int start_m, int start_d, int end_y, int end_m, int end_d)
{
    int y1, m1, d1, y2, m2, d2;

    m1 = (start_m + 9) % 12;
    y1 = start_y - m1 / 10;
    d1 = y1*365 + y1/4 - y1/100 + y1/400 + (m1*306 + 5) / 10 + (start_d-1);
    
    m2 = (end_m + 9) % 12;
    y2 = end_y - m2 / 10;
    d2 = y2*365 + y2/4 - y2/100 + y2/400 + (m2*306 + 5) / 10 + (end_d-1);

    return d2 - d1;
}
int Fibo(int n)
{
    if (n==2 || n==1)
        return 1;
    else return Fibo(n-1)+Fibo(n-2);
}
void fun1()
{
    int i;
    float sum = 0.0;
    for (i = 2; i <= 21; i++)
        sum += Fibo(i+1)*1.0 / Fibo(i);
    printf("方法一：前20项和为：%f\n", sum);
}
void fun2()
{
    // 设an = x/y，则an+1 = (x+y)/x
    int i, t;
    float x, y, sum = 0;
    x = 2, y = 1;
    for (i = 0; i < 20; i++)
    {
        sum += x / y;
        t = x;x = x + y; y = t;
    }
    printf("方法二：前20项和为：%f\n", sum);
}
void sum_an()
{
    fun1();
    fun2();
}
void unique_num()
{
    int i, j, k, count = 0;;
    for (i = 1; i <= 4; i++)
        for (j = 0; j <= 4; j++)
            for (k = 0; k <= 4; k++)
                if (i != j && i != k && j != k)
                {
                    printf("%d ", i*100+j*10+k);
                    count++;
                    if (count % 10 == 0) putchar('\n');
                }
    printf("\n共有%d个3位数\n", count);
}
void prime_factor()
{
    int n, k = 2;
    printf("请输入一个大于或等于2的整数：");
    scanf("%d", &n);
    printf("质因子分解结果：%d=", n);
    while (1)
    {
        if (n % k == 0)
        {
            n /= k;
            if (n > 1)
                printf("%d*", k);
            else
            {
                printf("%d\n", k);  // 分解完毕
                break;
            }
        }
        else
            k++;
    }
}
void sort_select()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t, max_index;
    for (i = 0; i < 10; i++)
    {
        max_index = i;
        for (j = i; j < 10; j++)
        {
            if (a[j] > a[max_index])    // 找到最大的一个数的下标
            {
                max_index = j;
            }
        }
        if (a[max_index] != a[i])  // 若找到最大的数，则交换
        {
            t = a[i];
            a[i] = a[max_index];
            a[max_index] = t;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
}
void sort_bubble()
{
    int a[10] = {8,3,5,-1,33,23,10,-52,12,44};
    int i, j, t;
    for (i = 1; i < 10; i++)
        for (j = 1; j < 10-i; j++)
            if (a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
}
void same_number()
{
    int i, t, n, flag = 0, count[10] = {0};
    printf("请输入一个正整数：");
    scanf("%d", &n);
    t = n;
    while (t)
    {
        count[t % 10]++;    // 取该整数的每一位，并统计频数
        t /= 10;
    }
    for (i = 0; i < 10; i++)
        if (count[i] > 1)
            flag = 1;
    if (flag)
        printf("整数%d存在相同的数字\n", n);
    else
        printf("整数%d没有相同的数字\n", n);
}
// 本题只包含+-两种运算符，若还包括*/运算符，请读者自行思考如何实现计算
void sample_calculation()
{
    float left, right;
    char op;
    printf("请输入一个算数表达式：");
    scanf("%f", &left);
    op = getchar();
    scanf("%f", &right);
    printf("结果为：%f\n", evaluate(left, op, right));
}
float evaluate(float left, char op, float right)
{
    float res;
    if (op == '+') res = left+right;
    else if (op == '-') res = left-right;
    else if (op == '*') res = left*right;
    else if (op == '/')
    {
        if (right == 0)
        {
            printf("分母不能为0！\n");
            exit(1);
        }
        else
        {
            res = left / right;
        }
    }
    else
        printf("非法的输入！\n");
    return res;
}
void insert_arr()
{
    int a[10]={1,3,5,7,9}, n, * p;
    printf("原数组：");
    for (p=a; *p; p++)
        printf("%d  ", *p);
    printf("\n");
    printf("输入要插入的数:");
    scanf("%d", &n);
    p = a;
    while (*p)   // 定位到结束符
        p++;
    while (*(p-1)>n)    // 移动
    {
        *p = *(p-1);
        p--;
    }
    *p = n;
    printf("新数组：");
    for (p=a; *p; p++)
        printf("%d   ", *p);
    printf("\n");
}
void fine_a_an_dian()
{
    int a[4][4] = {
        {1,2,3,4},
        {4,10,1,5},
        {0,1,2,3},  //  有一个鞍点，鞍点为a[2][3] = 3 
        {11,11,11,11}};
    int i, j, k, posti, postj, flag;
    for (i = 0; i < 4; i++)
    {
        flag = 1;
        for (j = 0; j < 4; j++)
        {
            posti = i, postj = 0;   // 默认值
            if (a[i][j] > a[posti][postj]) posti=i, postj=j; // 找到该行最大值的坐标
        }
        for (k = 0; k < 4; k++) // 与该列的其他值比较
            if (a[posti][postj] > a[k][postj])
                flag = 0;
        if (flag == 1)
            printf("鞍点为a[%d][%d]=%d\n", posti, postj, a[posti][postj]);
    }
}
void binary_search()
{
    int i, n, low=0, high=9, mid, flag = 0,a[10]={1,2,3,5,7,12,14,22,25,44};
    for (i=0; i<10; i++) printf("%d  ", a[i]);
    printf("\n请输入一个要查找的数：");
    scanf("%d", &n);
    while (low <= high) // 注意1：≤
    {
        mid = (low + high) / 2;
        if (n == a[mid])
        {
            flag = 1;
            break;
        }
        else if (n < a[mid]) high = mid - 1;    // 注意2：不是等于mid
        else low = mid + 1;
    }
    flag ? printf("数组中第%d个数是%d\n", mid+1, n) : printf("数组中没有%d这个数\n", n);
}
void bao_shu()
{
    int i, cur = 0, cout, a[8] = {1,2,3,4,5,6,7,8}, * p = a;
    for (i = 0; i < 7; i++) // 控制出队人数，此时出队7人
    {
        for (cout = 0; cout < 3; cur++, cur %= 8)   // 报数形式：3个一循环
        {
            if (a[cur] != 0) cout++;
            if (cout == 3) 
            {
                printf("%3d", a[cur]);
                a[cur] = 0;
            }
        }

    }
    while (*p == 0) p++;
    printf("\n最后剩下的是%d号\n", *p);
}
char * int_to_hex(int n)
{
    static int i = 0;
    if (n < 16)
    {
        if (n < 10)
            buffer[i] = n + '0';
        else
            buffer[i] = n - 10 + 'A';
        buffer[i+1] = '\0';
    }
    else
    {
        int_to_hex(n / 16);
        n %= 16;
        i++;
        if (n < 10)
            buffer[i] = n + '0';
        else
            buffer[i] = n - 10 + 'A';
    }
    return buffer;
}