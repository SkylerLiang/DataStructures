#ifndef __EX2_H
#define __EX2_H

#define QueueSize 10

typedef int DataType;

typedef struct
{
    DataType data[QueueSize];
    int front, rear;
} CQueue;

void errorHandler(int err);
int getState1();
int getState2(CQueue *cq);
int deQueue(CQueue *cq, DataType *ptr);
int enQueue(CQueue *cq, DataType x);
void aa(CQueue *q);
void print(CQueue *cq);

#endif