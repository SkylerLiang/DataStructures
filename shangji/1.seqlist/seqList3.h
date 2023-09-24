#ifndef __SEQLIST_H
#define __SEQLIST_H

#define MAXNUM 100

typedef int ElemType;
typedef struct
{
    ElemType data[MAXNUM];
    int length;
}SeqList;

ElemType test1[] = {1,4,9,16,25,36,49,64,81,100};
ElemType test2[] = {1,2,3,4,5,6,7,8,9};

void InitList(SeqList *L);  // 初始化顺序表
void CreateList(SeqList *L);    // 创建顺序表
void PrintList(SeqList L);  // 打印顺序表
void ReverseList(SeqList *L);   // 逆置顺序表，方法1
void ReverseList2(SeqList *L);  // 逆置顺序表，方法2

#endif