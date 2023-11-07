#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// 创建函数，输入字符串，用*表示空指针，以先序框架创建二叉树。（二叉链表存储）
BiNode *CreateBiTree(BiNode *T, char *str)
{
    static int i = 0;
    char ch = str[i++];
    if (ch == '*')
        T = NULL;
    else
    {
        T = (BiNode *)malloc(sizeof(BiNode));
        T->data = ch;
        T->lchild = CreateBiTree(T->lchild, str);
        T->rchild = CreateBiTree(T->rchild, str);
    }
    return T;
}

// 中序遍历二叉树
void InOrder(BiNode *T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

// 后序遍历二叉树
void PostOrder(BiNode *T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}

// 求二叉树的深度
int Depth(BiNode *T)
{
    if (T == NULL)
        return 0;
    else
    {
        int ldepth, rdepth;
        ldepth = Depth(T->lchild);
        rdepth = Depth(T->rchild);
        return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
    }
}

// 求二叉树的宽度
int Width(BiNode *T)
{
    if (T == NULL)
        return 0;
    else
    {
        int lwidth, rwidth;
        lwidth = Width(T->lchild);
        rwidth = Width(T->rchild);
        return (lwidth > rwidth) ? (lwidth + rwidth) : (rwidth + lwidth);
    }
}

int main()
{
    BiNode *T = NULL;
    char str[] = "ABD**E**CF***";
    T = CreateBiTree(T, str);
    printf("中序遍历二叉树：");
    InOrder(T);
    printf("\n");
    printf("后序遍历二叉树：");
    PostOrder(T);
    printf("\n");
    printf("二叉树的深度为：%d\n", Depth(T));
    printf("二叉树的宽度为：%d\n", Width(T));
    return 0;
}