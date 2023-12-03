#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main()
{
    BiNode *T = NULL;
    char str[] = "ABD**E**CF*1*";
    if (!IsLegal(str))
        ErrorHandle(1);
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
        if (T == NULL)
            exit(2);
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
int LevelWidth(BiNode *root, int level)
{
    if (!root)
        return 0;
    else
    {
        if (level == 1)
            return 1;
        level = LevelWidth(root->lchild, level - 1) + LevelWidth(root->rchild, level - 1);
    }
    return level;
}

int Width(BiNode *root)
{
    int width, i;
    int w[20];
    for (i = 0; i < 20; i++)
        w[i] = 0;
    if (!root)
        width = 0;
    else
    {
        for (i = 0; i <= Depth(root); i++)
            w[i] = LevelWidth(root, i + 1);
    }
    i = 0;
    while (w[i])
    {
        if (w[i] > width)
            width = w[i];
        i++;
    }
    return width;
}

// 判断输入是否合法
int IsLegal(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '*' && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

// 错误处理
void ErrorHandle(int errorType)
{
    switch (errorType)
    {
    case 1:
        printf("输入不合法！\n");
        exit(1);
        break;
    case 2:
        printf("内存分配失败！\n");
        exit(2);
        break;
    default:
        break;
    }
}
