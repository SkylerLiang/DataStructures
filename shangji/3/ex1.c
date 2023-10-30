#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// 必须输入正数
int main()
{
    int x;
    Lstack lstack;
    lstack.top = NULL;
    lstack.length = 0;
    printf("请输入数据元素：\n");
    scanf("%d", &x);
    if (x < 0)
    {
        errorHandler(3);
    }
    while (x != 0)
    {
        push(&lstack, x);
        scanf("%d", &x);
        if (x < 0)
        {
            errorHandler(3);
        }
    }
    printf("进栈后的数据元素：\n");
    print(&lstack);

    int i = lstack.length;
    printf("出栈的数据元素：\n");
    while (lstack.top != NULL)
    {
        x = pop(&lstack);
        printf("%d ", x);
    }
    printf("\n");
    printf("出栈次数：%d\n", i);
    return 0;
}

// 错误处理
void errorHandler(int err)
{
    switch (err)
    {
    case 1:
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    case 2:
    {
        printf("下溢错误！\n");
        exit(2);
    }
    case 3:
    {
        printf("输入错误！\n");
        exit(3);
    }
    }
}

// 进栈函数
int push(Lstack *ls, DataType x)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        errorHandler(1);
    if (p != NULL)
    {
        p->data = x;
        p->next = ls->top;
        ls->top = p;
        ls->length++;
        return 1;
    }
    return 0;
}

// 出栈函数
int pop(Lstack *LS)
{
    Node *p;
    DataType ptr;
    p = LS->top;
    if (LS->top == NULL)
        errorHandler(2);
    ptr = LS->top->data;
    LS->top = LS->top->next;
    LS->length--;
    free(p);
    return ptr;
}

// 打印栈中元素
void print(Lstack *ls)
{
    Node *p;
    p = ls->top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
