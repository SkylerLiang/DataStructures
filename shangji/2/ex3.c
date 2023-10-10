#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {2, 4, 6, 8, 10};
    int arr3[5] = {1, 4, 5, 8, 9};
    int arr4[5] = {2, 4, 6, 8, 10};
    int arr5[5] = {1, 3, 2, 4, 5};
    Node *A = CreateList(arr1, 5);
    Node *B = CreateList(arr2, 5);
    Node *C = CreateList(arr3, 5);
    Node *D = CreateList(arr4, 5);
    Node *E = CreateList(arr5, 5);
    printf("A: ");
    PrintList(A);
    IsRising(A);
    printf("B: ");
    PrintList(B);
    IsRising(B);
    A = Merge(A, B);
    printf("合并AB后A: ");
    PrintList(A);
    printf("C: ");
    PrintList(C);
    IsRising(C);
    printf("D: ");
    PrintList(D);
    IsRising(D);
    C = Merge(C, D);
    printf("合并CD后C: ");
    PrintList(C);

    printf("E: ");
    PrintList(E);
    IsRising(E);
    return 0;
}

// 从数组创建链表
Node *CreateList(int *arr, int length)
{
    Node *first = (Node *)malloc(sizeof(Node));
    if (first == NULL)
        ErrorHandler(1);
    Node *p = first;
    Node *q;
    int i = 0;

    while (i < length)
    {
        q = (Node *)malloc(sizeof(Node));
        if (q == NULL)
            ErrorHandler(1);
        q->data = arr[i++];
        p->next = q;
        p = q;
    }
    p->next = NULL;
    return first;
}

// 打印链表
void PrintList(Node *first)
{
    Node *p = first->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 将La，Lb两个递增有序单链表合并成一个递减有序的单链表，不允许有重复元素，将Lb的元素合并到La中，返回La
Node *Merge(Node *A, Node *B)
{
    Node *p = A->next;
    Node *q = B->next;
    Node *r;
    Node *s;
    Node *t;
    Node *first = (Node *)malloc(sizeof(Node));
    if (first == NULL)
        ErrorHandler(1);
    first->next = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            r = p;
            p = p->next;
            r->next = first->next;
            first->next = r;
        }
        else if (p->data > q->data)
        {
            r = q;
            q = q->next;
            r->next = first->next;
            first->next = r;
        }
        else
        {
            r = p;
            p = p->next;
            s = q;
            q = q->next;
            r->next = first->next;
            first->next = r;
            s->next = first->next;
            first->next = s;
        }
    }
    while (p != NULL)
    {
        r = p;
        p = p->next;
        r->next = first->next;
        first->next = r;
    }
    while (q != NULL)
    {
        r = q;
        q = q->next;
        r->next = first->next;
        first->next = r;
    }
    t = first;
    first = first->next;
    free(t);
    Delete(first);
    return first;
}

//链表删除相邻的重复元素
void Delete(Node *first)
{
    Node *p = first->next;
    Node *q;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}

// 检查链表是否递增
void IsRising(Node *first)
{
    Node *p = first->next;
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
            ErrorHandler(2);
        p = p->next;
    }
}

void ErrorHandler(int error_code)
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
        printf("链表非递增\n");
        exit(2);
    }
    }
}