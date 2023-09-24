#ifndef __SEQLIST_H
#define __SEQLIST_H

#define MAX 10

typedef int ElemType;
typedef struct
{
    ElemType data[MAX];
    int length;
}SeqList;

void ErrorHandler(int errType); //错误处理函数
void InitList(SeqList *L);  //初始化顺序表
void CreateList(SeqList *L);    //创建顺序表
void InsertList(SeqList *L);    //插入元素
void DeleteList(SeqList *L);    //删除元素
void PrintList(SeqList L);  //输出顺序表

#endif
