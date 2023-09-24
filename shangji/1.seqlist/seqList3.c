#include <stdio.h>
#include "seqList3.h"

int main()
{
    SeqList L;

    InitList(&L);
    CreateList(&L);
    PrintList(L);

    printf("逆置第一次\n");
    ReverseList(&L);
    PrintList(L);

    printf("逆置第二次\n");
    ReverseList2(&L);
    PrintList(L);

    return 0;
}

void CreateList(SeqList *L)
{
    int i;
    int n = sizeof(test1)/sizeof(test1[0]); //计算数组的长度

    for(i = 0; i < n; i++)
    {
        L->data[i] = test1[i];
    }

    L->length = n;
}

void InitList(SeqList *L)
{
    L->length = 0;
}

void PrintList(SeqList L)
{
    int i;

    printf("顺序表中的元素为：");
    for(i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

//逆置顺序表, 用一个临时变量
void ReverseList(SeqList *L)
{
    int i;
    ElemType temp;
    for(i = 0; i < ((L->length)/2); i++)
    {
        temp = L->data[i];
        L->data[i] = L->data[L->length-i-1];
        L->data[L->length-i-1] = temp;
    }
}

//逆置顺序表, 用新顺序表
void ReverseList2(SeqList *L)
{
    int i;
    SeqList L2;

    for(i = 0; i < L->length; i++)  //将L中的元素逆置到L2中
    {
        L2.data[i] = L->data[L->length-i-1];
    }

    for(i = 0; i < L->length; i++)  //将L2中的元素复制到L中
    {
        L->data[i] = L2.data[i];
    }
}

