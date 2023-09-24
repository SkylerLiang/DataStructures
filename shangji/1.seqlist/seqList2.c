#include <stdio.h>
#include <stdlib.h>
#include "seqList2.h"

int main()
{
    SeqList L;
    ElemType x;

    InitList(&L);
    CreateList(&L);
    PrintList(L);

    if(IsIncrease(L))
    {
        printf("顺序表是递增的\n");
    }
    else
    {
        printf("顺序表不是递增的\n");
        exit(1);
    }

    printf("请输入要插入的元素：");
    scanf("%d", &x);
    InsertList(&L, x);
    PrintList(L);

    return 0;
}

void InitList(SeqList *L)
{
    L->length = 0;
}

//判断顺序表是否有序
int IsIncrease(SeqList L)
{
    int i;

    for(i = 0; i < L.length-1; i++)
    {
        if(L.data[i] > L.data[i+1])
        {
            return 0;
        }
    }

    return 1;
}

void CreateList(SeqList *L)
{
    int i;

    for(i = 0; i < elenum; i++)
    {
        L->data[i] = test1[i];
    }

    L->length = elenum;
}


void InsertList(SeqList *L, ElemType x)
{
    int i, j;

    for(i = 0; i < L->length; i++)  //找到第一个大于x的元素
    {
        if(L->data[i] > x)
        {
            break;
        }
    }

    for(j = L->length; j > i; j--)  //将第i个元素及其后面的元素后移
    {
        L->data[j] = L->data[j-1];
    }

    L->data[i] = x;
    L->length++;
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




