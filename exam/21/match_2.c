#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    char val;
    struct node * next;
} NODE, * PNODE;
typedef struct stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, * PSTACK;

void push(PSTACK pS, char val);
BOOL pop(PSTACK pS);
BOOL match(PSTACK pS, char * str);
int main()
{
    STACK S;
    char str[30];
    // 初始化栈
    S.pTop = (PNODE)malloc(sizeof(NODE));
    S.pBottom = S.pTop;
    S.pTop->next = NULL;
    
    for (int i = 0; i < 5; i++)
    {
        printf("输入一串含括号的字符串：");
        gets(str);
        match(&S, str) ? printf("正确的括号使用！\n") : printf("错误的括号使用！\n");
    }
    system("pause");
    return 0;
}
BOOL match(PSTACK pS, char * str)
{
    // 清空栈
    pS->pTop = pS->pBottom;
    while (*str)
    {
        // 若遇到左括号，则入栈
        if (*str == '(' || *str == '[' || *str == '{')
            push(pS, *str);
        // 若遇到右括号，则与栈顶元素进行匹配
        else if (*str == ')' && pS->pTop->val == '(' || 
        *str == ']' && pS->pTop->val == '[' || 
        *str == '}' && pS->pTop->val == '{')
            pop(pS);    // 匹配成功出栈
        str++;
    }
    if (pS->pTop == pS->pBottom) return TRUE;
    else return FALSE;
}
void push(PSTACK pS, char val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->val = val;
    pNew->next = pS->pTop;
    pS->pTop = pNew;
}
BOOL pop(PSTACK pS)
{
    PNODE p = pS->pTop;
    if (pS->pTop == pS->pBottom) {
        printf("出栈失败！\n");
        return FALSE;
    }
    pS->pTop = pS->pTop->next;
    free(p);
    return TRUE;
}