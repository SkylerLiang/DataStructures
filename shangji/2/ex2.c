#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

SeqL testList[4] =
    {
        {5, {1, 3, 5, 7, 9}},
        {5, {2, 4, 6, 8, 10}},
        {5, {1, 4, 5, 8, 9}},
        {5, {1, 4, 8, 5, 9}}};

int main()
{
    SeqL C;

    for (int i = 1; i < 4; i++)
    {
        SeqL A = testList[0];
        SeqL B = testList[i];
        printf("A: ");
        PrintList(&A);
        IsRising(&A);
        printf("B: ");
        PrintList(&B);
        IsRising(&B);
        Merge(&A, &B, &C);
        printf("C: ");
        PrintList(&C);
        printf("\n");
    }

    return 0;
}
//

// 将两个递增有序的顺序表合并为一个新的递增有序顺序表，要求没有重复元素
void Merge(SeqL *A, SeqL *B, SeqL *C)
{
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length)
    {
        if (A->data[i] < B->data[j])
        {
            C->data[k++] = A->data[i++];
        }
        else if (A->data[i] > B->data[j])
        {
            C->data[k++] = B->data[j++];
        }
        else
        {
            C->data[k++] = A->data[i++];
            j++;
        }
    }
    while (i < A->length)
    {
        C->data[k++] = A->data[i++];
    }
    while (j < B->length)
    {
        C->data[k++] = B->data[j++];
    }
    C->length = k;
}

// 打印顺序表
void PrintList(SeqL *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 判断顺序表是否递增有序
int IsRising(SeqL *L)
{
    for (int i = 0; i < L->length - 1; i++)
    {
        if (L->data[i] > L->data[i + 1])
        {
            printf("顺序表不是递增有序的\n");
            exit(1);
        }
    }
    return 1;
}
