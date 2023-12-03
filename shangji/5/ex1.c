#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, key, count = 0;

    printf("请输入序列长度：");
    scanf("%d", &n);
    if (n <= 0)
        errorHandler(1);
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    if (a == NULL || b == NULL)
        errorHandler(4);

    printf("请输入序列：");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    BSTNode *T = NULL;
    for (i = 0; i < n; i++)
        createBST(&T, a[i]);
    printf("中序遍历：");
    inOrder(T, b);

    printf("\n请输入要查找的关键字：");
    scanf("%d", &key);
    if (key < 0 || key > 100)
        errorHandler(3);

    printf("顺序查找结果：");
    int result = seqSearch(a, n, key);
    if (result == -1)
        printf("查找失败\n");
    else
        printf("查找成功，经过了%d次比较\n", result + 1);

    printf("二分查找结果：");
    result = binSearch(b, n, key);
    if (result == -1)
        printf("查找失败\n");
    else
        printf("查找成功，经过了%d次比较\n", result + 1);

    printf("二叉排序树查找结果：");
    result = BSTSearch(T, key, &count);
    if (result == -1)
        printf("查找失败\n");
    else
        printf("查找成功，经过了%d次比较\n", count);
    return 0;
}

// 顺序查找
int seqSearch(int *a, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

// 二分查找
int binSearch(int *a, int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// 创建二叉排序树
void createBST(BSTNode **T, int key)
{
    if (*T == NULL)
    {
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        if (*T == NULL)
            errorHandler(4);
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
    }
    else if (key < (*T)->data)
        createBST(&(*T)->lchild, key);
    else if (key > (*T)->data)
        createBST(&(*T)->rchild, key);
}

// 中序遍历，存入数组b
void inOrder(BSTNode *T, int *b)
{
    static int i = 0;
    if (T != NULL)
    {
        inOrder(T->lchild, b);
        printf("%d ", T->data);
        b[i++] = T->data;
        inOrder(T->rchild, b);
    }
}

// 二叉排序树查找
int BSTSearch(BSTNode *T, int key, int *count)
{
    if (T == NULL)
        return -1;
    else if (key == T->data)
        return 1;
    else if (key < T->data)
    {
        (*count)++;
        return BSTSearch(T->lchild, key, count);
    }
    else
    {
        (*count)++;
        return BSTSearch(T->rchild, key, count);
    }
}

void errorHandler(int code)
{
    switch (code)
    {
    case 1:
        printf("输入的序列长度不合法\n");
        exit(1);
        break;
    case 2:
        printf("输入的序列不合法\n");
        exit(2);
        break;
    case 3:
        printf("输入的关键字不合法\n");
        exit(3);
        break;
    case 4:
        printf("内存分配失败\n");
        exit(4);
        break;
    default:
        break;
    }
}

