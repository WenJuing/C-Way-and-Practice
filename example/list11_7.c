// 链表的使用
// 以存放学生学籍信息为例，实现学生数据的增加、删除和修改等操作
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    long id;        // 学号
    char name[20];  // 姓名
    int age;        // 年纪
    float score;    // 成绩
} Stu;
typedef struct Node {        // 定义节点
    Stu stu;                 // 定义节点的数据域
    struct Node * next;      // 定义节点的指针域
} Node;
Node * list_create();             // 创建带头节点的链表
void traverse(Node * pHead);      // 遍历链表
bool insert_node(Node * pHead, Stu * stu, int pos);   // 插入学生信息
bool delete_node(Node * pHead, int pos);              // 删除学生信息
int list_length(Node * pHead);    // 计算链表的长度
int main()
{
    Node * pHead = list_create();
    Stu stu1 = {100, "yang", 12, 120};
    traverse(pHead);
    insert_node(pHead, &stu1, 2);
    traverse(pHead);
    delete_node(pHead, 2);
    traverse(pHead);
    system("pause");
    return 0;
}
Node * list_create()
{
    int id, age;
    float score;
    char name[20];
    Node * pHead = (Node*)malloc(sizeof(Node)), * pTail, * pNew;
    pTail = pHead, pTail->next = NULL;
    printf("请输入学生信息（学号/姓名/年龄/成绩），输入-1结束：\n");
    while (1)
    {
        scanf("%d %s %d %f", &id, name, &age, &score);
        if (id == -1 || age == -1 || score == -1) break;
        pNew = (Node*)malloc(sizeof(Node)); // 生成新节点
        pNew->stu.id = id, pNew->stu.age = age, pNew->stu.score = score;
        strcpy(pNew->stu.name, name);
        pTail->next = pNew;
        pTail = pNew;
    }
    pTail->next = NULL; // 最后一个节点指向空
    return pHead;
}
void traverse(Node * pHead)
{
    Node * p = pHead->next;
    printf("学号\t姓名\t年龄\t入学成绩\n");
    while (p)
    {
        printf("%d\t%s\t%d\t%.2f\n", p->stu.id, p->stu.name, p->stu.age, p->stu.score);
        p = p->next;
    }
    printf("学生总数：%d人\n", list_length(pHead));
}
bool insert_node(Node * pHead, Stu * stu, int pos)
{
    int len = list_length(pHead);
    if (pos <= 0 || pos > len+1)
        return false;
    Node * p = pHead, * pNew = (Node*)malloc(sizeof(Node));
    pNew->stu.id = stu->id, pNew->stu.age = stu->age, pNew->stu.score = stu->score;
    strcpy(pNew->stu.name, stu->name);
    for (int i = 0; i < pos - 1; i++)   // 让p指向插入位置的前一个位置
        p = p->next;
    pNew->next = p->next;   // 插入操作
    p->next = pNew;
    return true;
}
bool delete_node(Node * pHead, int pos)
{
    Node * p = pHead, * q;
    int len = list_length(pHead);
    if (pHead->next == NULL)    // 空链表
        return false;
    if (pos <= 0 || pos > len)  // 删除位置不对
        return false;
    for (int i = 0; i < pos - 1; i++)   // 让p指向插入位置的前一个位置
        p = p->next;
    q = p->next;
    p->next = p->next->next;
    free(q);
    return true;
}
int list_length(Node * pHead)
{
    int len = 0;
    Node * p = pHead->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}