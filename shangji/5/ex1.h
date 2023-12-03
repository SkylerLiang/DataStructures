#ifndef __EX1_H__
#define __EX1_H__

typedef struct BSTNode
{
    BSTNode *lchild;
    BSTNode *rchild;
    int data;
} BSTNode;

int seqSearch(int *a, int n, int key);
int binSearch(int *a, int n, int key);
void createBST(BSTNode **T, int key);
void inOrder(BSTNode *T, int *b);
int BSTSearch(BSTNode *T, int key, int *count);
void errorHandler(int code);


#endif // __EX1_H__
