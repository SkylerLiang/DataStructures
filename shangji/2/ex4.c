#include <stdio.h>
#include <stdlib.h>
#include "ex4.h"

int main()
{
    int n, m;
    printf("请输入人数n和报数m:");
    scanf("%d,%d", &n, &m);
    if (n <= 0 || m <= 0)
        ErrorHandling(2);
    Node *first = CreateList(n);
    Josephus(first, m);
    return 0;
}

// 创建循环链表
Node *CreateList(int length)
{
    Node *first = (Node *)malloc(sizeof(Node));
    if (first == NULL)
        ErrorHandling(1);
    Node *p = first;
    Node *q;
    int i = 0;

    while (i < length)
    {
        q = (Node *)malloc(sizeof(Node));
        if (q == NULL)
            ErrorHandling(1);
        q->data = i + 1;
        p->next = q;
        p = q;
        i++;
    }
    p->next = first->next;
    return first;
}

// 用循环链表实现约瑟夫环
void Josephus(Node *first, int m)
{
    Node *p = first;
    Node *q;
    int i = 0;
    p = p->next;
    while (p->next != p)
    {
        i++;
        if (i == m - 1)
        {
            q = p->next;
            p->next = q->next;
            printf("%d ", q->data);
            free(q);
            i = 0;
        }
        p = p->next;
    }
    printf("%d\n", p->data);
    free(p);
}

void ErrorHandling(int error_code)
{
    switch (error_code)
    {
    case 1:
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    case 2:
    {
        printf("输入有误\n");
        exit(2);
    }
    }
}
