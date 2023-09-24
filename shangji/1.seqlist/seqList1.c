#include <stdio.h>
#include <stdlib.h>
#include "seqList1.h"

int main(void)
{
    SeqList L;
    InitList(&L);
    CreateList(&L);
    PrintList(L);
    InsertList(&L);
    PrintList(L);
    DeleteList(&L);
    PrintList(L);
    return 0;
}

//错误处理函数, 1表示顺序表已满, 2表示插入位置不合法, 3表示删除位置不合法
void ErrorHandler(int errType)
{
    switch(errType)
    {
        case 1:
        {
            printf("顺序表已满，无法插入！\n");
            break;
        }
        case 2:
        {
            printf("插入位置不合法！\n");
            break;
        }
        case 3:
        {
            printf("删除位置不合法！\n");
            break;
        }
    }
    exit(errType);
}

void InitList(SeqList *L)
{
    L->length = 0;
}

//创建顺序表, 以-1结束, 顺序表的长度不超过MAX
void CreateList(SeqList *L)
{
    int i;

    printf("请输入顺序表中的元素，以-1结束\n");
    scanf("%d", &i);

    while(i != -1 && L->length < MAX)
    {
        L->data[L->length] = i;
        L->length++;
        scanf("%d", &i);
    }
}

//插入元素, 插入位置不超过顺序表的长度+1
void InsertList(SeqList *L)
{
    int i, j, x;

    printf("请输入要插入的元素：");
    scanf("%d", &x);
    printf("请输入要插入的位置：");
    scanf("%d", &i);

    if(L->length == MAX)
    {
        ErrorHandler(1);
    }
    else if(i < 1 || i > L->length + 1)
    {
        ErrorHandler(2);
    }
    else
    {
        for(j = L->length - 1; j >= i - 1; j--)
        {
            L->data[j + 1] = L->data[j];
        }

        L->data[i - 1] = x;
        L->length++;
    }
}

//删除元素, 删除位置不超过顺序表的长度
void DeleteList(SeqList *L)
{
    int i, j;

    printf("请输入要删除的位置：");
    scanf("%d", &i);

    if(i < 1 || i > L->length)
    {
        ErrorHandler(3);
    }
    else
    {
        for(j = i; j < L->length; j++)
        {
            L->data[j - 1] = L->data[j];
        }

        L->length--;
    }
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


