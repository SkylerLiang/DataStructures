#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int a[10] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    // int b[10] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    // int c[10] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    // int d[10] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    // int e[10] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    int a[10] = {513, 87, 512, 61, 908, 170, 87, 275, 653, 462};
    int b[10] = {513, 87, 512, 61, 908, 170, 87, 275, 653, 462};
    int c[10] = {513, 87, 512, 61, 908, 170, 87, 275, 653, 462};
    int d[10] = {513, 87, 512, 61, 908, 170, 87, 275, 653, 462};
    int e[10] = {513, 87, 512, 61, 908, 170, 87, 275, 653, 462};
    printf("原始数据：");
    printArray(a, 10);
    printf("\n");
    printf("简单选择排序：\n");
    selectSort(a, 10);
    printf("\n");
    printf("直接插入排序：\n");
    insertSort(b, 10);
    printf("\n");
    printf("改进的冒泡排序：\n");
    bubbleSort(c, 10);
    printf("\n");
    printf("快速排序：\n");
    quickSort(d, 0, 9);
    printArray(d, 10);
    printf("\n");
    printf("归并排序：\n");
    mergeSort(e, 0, 9);
    printArray(e, 10);
    return 0;
}

// 简单选择排序
void selectSort(int *a, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i; // 记录最小元素的下标
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j; // 更新最小元素的下标
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        printf("第%d趟排序结果：", i + 1);
        printArray(a, n);
    }
}

// 直接插入排序
void insertSort(int *a, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
        printf("第%d趟排序结果：", i);
        printArray(a, n);
    }
}

// 改进的冒泡排序
void bubbleSort(int *a, int n)
{
    int i, j, flag, temp;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0; // 标记本趟排序是否发生交换
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1; // 发生交换
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("第%d趟排序结果：", i + 1);
        printArray(a, n);
        if (flag == 0)
            break;
    }
}

// 快速排序
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(a, low, high);
        quickSort(a, low, pivotpos - 1);
        quickSort(a, pivotpos + 1, high);
    }
}

// 划分函数
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

// 归并排序
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// 归并函数
void merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = (int *)malloc(sizeof(int) * (high - low + 1));
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = 0; i < k; i++)
        a[low + i] = temp[i];
    free(temp);
}

// 打印数组
void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
