#ifndef __EX2_H
#define __EX2_H

typedef struct
{
    int length;
    int data[20];
} SeqL;

void Merge(SeqL *A, SeqL *B, SeqL *C);
void PrintList(SeqL *L);
int IsRising(SeqL *L);

#endif