#ifndef __SEQLIST_H
#define __SEQLIST_H

#define MAXNUM 100

int elenum = 10;

typedef int ElemType;
typedef struct
{
    ElemType data[MAXNUM];
    int length;
}SeqList;

ElemType test1[] = {1,4,9,16,25,36,49,64,81,100};
ElemType test2[] = {1,2,3,4,5,6,7,8,9,10};
ElemType test3[] = {10,9,8,7,6,5,4,3,2,1};

void InitList(SeqList *L);  //初始化顺序表
void CreateList(SeqList *L);    //创建顺序表
int IsIncrease(SeqList L);  //判断顺序表是否有序
void InsertList(SeqList *L, ElemType x);    //插入元素
void PrintList(SeqList L);  //输出顺序表

#endif