#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main()
{
    // 输入5 29 7 8 14 23 3 11
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree *T = CreateHuffmanTree(w, 8);
    PrintHuffmanCode(T, 8);
    return 0;
}

// 创建哈夫曼树
HuffmanTree *CreateHuffmanTree(int w[], int n)
{
    // 初始化哈夫曼树
    HuffmanTree *T = (HuffmanTree *)malloc(sizeof(HuffmanTree) * (2 * n - 1));
    if (T == NULL)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        T[i].parent = -1;
        T[i].lchild = -1;
        T[i].rchild = -1;
    }
    // 创建哈夫曼树
    for (int i = n; i < 2 * n - 1; i++)
    {
        int min1 = 99999, min2 = 99999;
        int x1 = -1, x2 = -1;
        for (int j = 0; j < i; j++)
        {
            if (T[j].parent == -1)
            {
                if (w[j] < min1)
                {
                    min2 = min1;
                    x2 = x1;
                    min1 = w[j];
                    x1 = j;
                }
                else if (w[j] < min2)
                {
                    min2 = w[j];
                    x2 = j;
                }
            }
        }
        T[i].weight = min1 + min2;
        T[i].lchild = x1;
        T[i].rchild = x2;
        T[x1].parent = i;
        T[x2].parent = i;
    }
    return T;
}

// 输出每个权值对应的二进制编码
void PrintHuffmanCode(HuffmanTree *T, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (T[j].parent != -1)
        {
            if (T[T[j].parent].lchild == j)
                printf("0");
            else
                printf("1");
            j = T[j].parent;
        }
        printf("\n");
    }
}
