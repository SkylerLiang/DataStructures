#ifndef __EX1_H
#define __EX1_H

// 用二叉链表存储二叉树，元素为字符
typedef struct BiNode
{
    char data;
    BiNode *lchild, *rchild;
} BiNode;

BiNode *CreateBiTree(BiNode *T, char *str);
void InOrder(BiNode *T);
void PostOrder(BiNode *T);
int Depth(BiNode *T);
int LevelWidth(BiNode *root, int level);
int Width(BiNode *root);
int IsLegal(char *str);
void ErrorHandle(int errorType);


#endif
