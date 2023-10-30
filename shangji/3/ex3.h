#ifndef __EX3_H
#define __EX3_H

#define StackSize 20

typedef struct
{
    int data[StackSize];
    int L_top, R_top;
} Stack;

void errorHandler(int err);
void initStack(Stack *stack);
void push(Stack *stack, int x, int id);
void pop(Stack *stack, int *ptr, int id);
int get(Stack *stack, int *ptr, int id);

#endif