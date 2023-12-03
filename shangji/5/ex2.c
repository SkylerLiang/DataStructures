#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable hashTable[40];

int main()
{
    int i;
    char name[6];
    int id;
    for (i = 0; i < 40; i++)
    {
        hashTable[i].id = 0;
    }
    printf("请输入37个学生的姓名和学号：\n");
    for (i = 0; i < 37; i++)
    {
        scanf("%s %d", name, &id);
        int index = hash(name);
        while (hashTable[index].id != 0)
        {
            index = (index + 1) % 40;
        }
        strcpy(hashTable[index].name, name);
        hashTable[index].id = id;
    }
    printf("请输入要查找的姓名：");
    scanf("%s", name);
    int index = hashSearch(name);
    if (index == -1)
        printf("查找错误！\n");
    else
        printf("学号：%d\n", hashTable[index].id);
    return 0;
}

// 哈希函数
int hash(char *name)
{
    int i, sum = 0;
    for (i = 0; i < strlen(name); i++)
    {
        sum += name[i];
    }
    return sum % 40;
}

// 哈希查找
int hashSearch(char *name)
{
    int index = hash(name);
    int i = 0;
    while (hashTable[index].id != 0 && strcmp(hashTable[index].name, name) != 0)
    {
        index = (index + 1) % 40;
        i++;
        if (i == 40)
            return -1;
    }
    if (hashTable[index].id == 0)
        return -1;
    else
        return index;
}
