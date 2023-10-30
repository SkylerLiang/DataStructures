#ifndef __EX1_H
#define __EX1_H

typedef unsigned int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
    int length;
} Lstack;

void errorHandler(int err);
int push(Lstack *ls, DataType x);
int pop(Lstack *LS);
void print(Lstack *ls);

#endif