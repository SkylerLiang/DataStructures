#ifndef __EX2_H
#define __EX2_H

typedef struct Triple
{
    unsigned int row, col;
    int data;
} Triple;

typedef struct Matrix
{
    Triple data[10];
    unsigned int row, col, num;
} Matrix;

Matrix *matrixAdd(Matrix *A, Matrix *B);
void PrintMatrix(Matrix *M);

#endif