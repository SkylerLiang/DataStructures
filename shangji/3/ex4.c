// 借助栈检查一个表达式的括号是否匹配

#include <stdio.h>
#include <stdlib.h>
#include "ex4.h"

int main()
{
    char str[100];
    printf("请输入一个表达式：\n");
    scanf("%s", str);
    if (check(str))
    {
        printf("括号匹配！\n");
    }
    else
    {
        printf("括号不匹配！\n");
    }
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
    }
}

// 初始化栈
void initStack(Stack *stack)
{
    stack->size = 0;
}

// 入栈
void push(Stack *stack, char x)
{
    if (stack->size == STACK_SIZE)
    {
        errorHandler(1);
    }
    stack->data[stack->size] = x;
    stack->size++;
}

// 出栈
int pop(Stack *stack, char *ptr)
{
    if (stack->size != 0)
    {
        stack->size--;
        *ptr = stack->data[stack->size];
        return 1;
    }
    else
    {
        return 0;
    }
}

// 检查括号是否匹配
int check(char *str)
{
    Stack stack;
    initStack(&stack);
    char *ptr = str;
    while (*ptr != '\0')
    {
        if (*ptr == '(')
        {
            push(&stack, *ptr);
        }
        else if (*ptr == ')')
        {
            char x;
            if (pop(&stack, &x) == 0)
            {
                return 0;
            }
                }
        ptr++;
    }
    if (stack.size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
