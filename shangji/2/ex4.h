#ifndef __EX4_H
#define __EX4_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *CreateList(int length);
void Josephus(Node *first, int m);
void ErrorHandling(int error_code);

#endif