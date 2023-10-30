#ifndef __EX4_H
#define __EX4_H

#define STACK_SIZE 10

typedef struct
{
    char data[STACK_SIZE];
    int size;
} Stack;

void errorHandler(int err);
void initStack(Stack *stack);
void push(Stack *stack, char x);
int pop(Stack *stack, char *ptr);
int check(char *str);

#endif