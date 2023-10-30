#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main()
{
    Stack stack;
    initStack(&stack);
    int i;

    for (i = 0; i < 10; i++)
    {
        push(&stack, i, i % 2);
    }
    // 输出栈顶元素
    int x;
    get(&stack, &x, 0);
    get(&stack, &x, 1);

    // 随机入栈出栈
    push(&stack, 10, 0);
    printf("左栈压入元素为:10\n");
    get(&stack, &x, 0);

    pop(&stack, &x, 1);
    printf("右栈弹出元素为:%d\n", x);
    get(&stack, &x, 1);

    pop(&stack, &x, 0);
    printf("左栈弹出元素为:%d\n", x);
    get(&stack, &x, 0);

    push(&stack, 11, 1);
    printf("右栈压入元素为:11\n");
    get(&stack, &x, 1);

    push(&stack, 12, 0);
    printf("左栈压入元素为:12\n");
    get(&stack, &x, 0);

    push(&stack, 13, 1);
    printf("右栈压入元素为:13\n");
    get(&stack, &x, 1);

    return 0;
}

// 错误处理
void errorHandler(int err)
{
    switch (err)
    {
    case 1:
    {
        printf("栈已满！\n");
        exit(1);
    }
    case 2:
    {
        printf("栈为空！\n");
        exit(2);
    }
    case 3:
    {
        printf("id输入错误！\n");
        exit(3);
    }
    }
}

// 初始化栈
void initStack(Stack *stack)
{
    stack->L_top = 0;
    stack->R_top = StackSize - 1;
}

// 入栈
void push(Stack *stack, int x, int id)
{
    if (stack->L_top == stack->R_top)
    {
        errorHandler(1);
    }
    if (id == 0)
    {
        stack->data[stack->L_top] = x;
        stack->L_top++;
    }
    else if (id == 1)
    {
        stack->data[stack->R_top] = x;
        stack->R_top--;
    }
    else
    {
        errorHandler(3);
    }
}

// 出栈
void pop(Stack *stack, int *ptr, int id)
{
    if (id == 0)
    {
        if (stack->L_top == 0)
        {
            errorHandler(2);
        }
        stack->L_top--;
        *ptr = stack->data[stack->L_top];
    }
    else if (id == 1)
    {
        if (stack->R_top == StackSize - 1)
        {
            errorHandler(2);
        }
        stack->R_top++;
        *ptr = stack->data[stack->R_top];
    }
    else
    {
        errorHandler(3);
    }
}

// 获取栈顶元素
int get(Stack *stack, int *ptr, int id)
{
    if (id == 0)
    {
        if (stack->L_top == 0)
        {
            errorHandler(2);
        }
        *ptr = stack->data[stack->L_top - 1];
        printf("左栈顶元素为:%d\n", *ptr);
    }
    else if (id == 1)
    {
        if (stack->R_top == StackSize - 1)
        {
            errorHandler(2);
        }
        *ptr = stack->data[stack->R_top + 1];
        printf("右栈顶元素为:%d\n", *ptr);
    }
    else
    {
        errorHandler(3);
    }
    return 1;
}
