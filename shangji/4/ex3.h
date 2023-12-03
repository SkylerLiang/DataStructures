#ifndef __EX3_H__
#define __EX3_H__

typedef struct
{
    unsigned int weight;
    int parent, lchild, rchild;
} HuffmanTree;

HuffmanTree *CreateHuffmanTree(int w[], int n);
void PrintHuffmanCode(HuffmanTree *T, int n);

#endif