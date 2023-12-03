#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

int main()
{
    int i = 0;
    Matrix A = {{{0, 0, 1}, {1, 1, 3}, {1, 2, 5}, {2, 3, 4}}, 3, 3, 4};
    Matrix B = {{{0, 0, 2}, {1, 1, 4}, {2, 1, 3}, {2, 2, 5}, {3, 1, 7}}, 3, 4, 5};
    Matrix *C = matrixAdd(&A, &B);
    PrintMatrix(C);
    printf("\n");
    return 0;
}

// 编写矩阵相加的算法，结果存放在三元组表C中，输入A和B，输出C。
Matrix *matrixAdd(Matrix *A, Matrix *B)
{
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    if (A->col != B->col || A->row != B->row)
        printf("注意：矩阵大小不同！\n");
    C->row = A->row > B->row ? A->row : B->row;
    C->col = A->col > B->col ? A->col : B->col;
    C->num = 0;
    int i = 0, j = 0, k = 0;
    while (i < A->num && j < B->num)
    {
        if (A->data[i].row < B->data[j].row)
        {
            C->data[k].row = A->data[i].row;
            C->data[k].col = A->data[i].col;
            C->data[k].data = A->data[i].data;
            C->num++;
            i++;
            k++;
        }
        else if (A->data[i].row > B->data[j].row)
        {
            C->data[k].row = B->data[j].row;
            C->data[k].col = B->data[j].col;
            C->data[k].data = B->data[j].data;
            C->num++;
            j++;
            k++;
        }
        else
        {
            if (A->data[i].col < B->data[j].col)
            {
                C->data[k].row = A->data[i].row;
                C->data[k].col = A->data[i].col;
                C->data[k].data = A->data[i].data;
                C->num++;
                i++;
                k++;
            }
            else if (A->data[i].col > B->data[j].col)
            {
                C->data[k].row = B->data[j].row;
                C->data[k].col = B->data[j].col;
                C->data[k].data = B->data[j].data;
                C->num++;
                j++;
                k++;
            }
            else
            {
                C->data[k].row = A->data[i].row;
                C->data[k].col = A->data[i].col;
                C->data[k].data = A->data[i].data + B->data[j].data;
                C->num++;
                i++;
                j++;
                k++;
            }
        }
    }
    if (i < A->num)
    {
        while (i < A->num)
        {
            C->data[k].row = A->data[i].row;
            C->data[k].col = A->data[i].col;
            C->data[k].data = A->data[i].data;
            C->num++;
            i++;
            k++;
        }
    }
    if (j < B->num)
    {
        while (j < B->num)
        {
            C->data[k].row = B->data[j].row;
            C->data[k].col = B->data[j].col;
            C->data[k].data = B->data[j].data;
            C->num++;
            j++;
            k++;
        }
    }
    return C;
}

// 打印矩阵
void PrintMatrix(Matrix *M)
{
    int i = 0;
    for (i = 0; i < M->num; i++)
    {
        printf("%d %d %d\n", M->data[i].row, M->data[i].col, M->data[i].data);
    }
}
