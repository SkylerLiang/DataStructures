#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

#define MAXNUM 10

int counter, flag;

int main()
{
    CQueue cq;
    cq.front = cq.rear = 0;
    int i;
    float x;
    printf("请输入数据元素：\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%f", &x);
        if (x - (int)x != 0)
        {
            errorHandler(3);
        }
        enQueue(&cq, x);
    }
    printf("调用aa前的数据元素：\n");
    print(&cq);
    aa(&cq);
    printf("调用aa后的数据元素：\n");
    print(&cq);
    return 0;
}

void errorHandler(int err)
{
    switch (err)
    {
    case 1:
    {
        printf("队列为空！\n");
        exit(1);
    }
    case 2:
    {
        printf("队列已满！\n");
        exit(2);
    }
    case 3:
    {
        printf("输入错误！\n");
        exit(3);
    }
    }
}

// 分别使用两种方法判别队空和队满

// 方法一
// 用一个计数变量counter记队列中的元素个数
int getState1()
{
    if (counter == 0)
    {
        return 1; // 空
    }
    else if (counter == MAXNUM)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// 方法二
// 设置标志位
int getState2(CQueue *cq)
{
    if (cq->rear == cq->front)
    {
        if (flag == 1)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

// 循环队列出队
int deQueue(CQueue *cq, DataType *ptr)
{
    if ((getState1() == 1) && (getState2(cq) == 1))
    {
        errorHandler(1);
    }
    else
    {
        *ptr = cq->data[cq->front];
        cq->front = (cq->front + 1) % MAXNUM;
        counter--;
        flag = 0;
    }
    return 1;
}

// 循环队列入队
int enQueue(CQueue *cq, DataType x)
{
    if ((getState1() == 2) && (getState2(cq) == 2))
    {
        errorHandler(1);
    }
    else
    {
        cq->data[cq->rear] = x;
        cq->rear = (cq->rear + 1) % MAXNUM;
        counter++;
        if (cq->front == cq->rear)
        {
            flag = 1;
        }
        return 1;
    }
}

// 把队列q中的元素一一出队列，如果是负数直接抛弃；如果是大于等于零，则插入到q的队尾。
void aa(CQueue *q)
{
    DataType x;
    for (int i = 0; i < 5; i++)
    {
        deQueue(q, &x);
        if (x >= 0)
        {
            enQueue(q, x);
        }
    }
}

// 打印循环队列
void print(CQueue *cq)
{
    int i;
    for (i = cq->front; i != cq->rear; i = (i + 1) % MAXNUM)
    {
        printf("%d ", cq->data[i]);
    }
    printf("\n");
}
