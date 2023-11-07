#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"


// 编写矩阵相加的算法，结果存放在三元组表C中，输入A和B，输出C。
Matrix *matrixAdd(Matrix *A, Matrix *B)
{
    Matrix *C = (Matrix *)malloc(sizeof(Matrix));
    C->row = A->row;
    C->col = A->col;
    C->num = 0;
    int i = 0, j = 0, k = 0;
    for(i = 0; i < A->num; i++)
    {
        for(j = 0; j < B->num; j++)
        {
            if(A->data[i].row == B->data[j].row && A->data[i].col == B->data[j].col)
            {
                C->data[k].row = A->data[i].row;
                C->data[k].col = A->data[i].col;
                C->data[k].data = A->data[i].data + B->data[j].data;
                C->num++;
                k++;
            }
        }
    }
}

int main()
{
    int i = 0;
    Matrix A = {{{0, 0, 1}, {1, 1, 2}, {2, 2, 3}, {2, 0, 4}}, 3, 3, 4};
    Matrix B = {{{0, 0, 1}, {1, 1, 2}, {2, 2, 3}, {1, 2, 5}}, 3, 3, 4};
    Matrix *C = matrixAdd(&A, &B);
    for (i = 0; i < C->num; i++)
    {
        printf("%d %d %d\n", C->data[i].row, C->data[i].col, C->data[i].data);
    }
    return 0;
}
