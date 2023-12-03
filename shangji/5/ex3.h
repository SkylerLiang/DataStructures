#ifndef __EX3_H
#define __EX3_H

void selectSort(int *a, int n);
void insertSort(int *a, int n);
void bubbleSort(int *a, int n);
void quickSort(int *a, int low, int high);
int partition(int *a, int low, int high);
void mergeSort(int *a, int low, int high);
void merge(int *a, int low, int mid, int high);
void printArray(int *a, int n);

#endif
