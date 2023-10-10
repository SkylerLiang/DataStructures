#ifndef __EX3_H
#define __EX3_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *CreateList(int *arr, int length);
void PrintList(Node *first);
Node *Merge(Node *A, Node *B);
void ErrorHandler(int error_code);
void IsRising(Node *first);
void Delete(Node *first);

#endif