#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

int main()
{
    Student *first;
    first = InitList();
    CreateList(first);
    PrintList(first);
    // 键盘输入学生学号，如果存在该学生，就删除该学生，否则就添加该学生
    long long id;
    printf("请输入要查询的学号：");
    scanf("%lld", &id);
    Student *p = FindPrevious(first, id);
    if (p != NULL)
    {
        printf("找到了该学生\n");
        printf("删除前：\n");
        PrintList(first);
        DeleteNode(p);
        printf("删除后：\n");
        PrintList(first);
    }
    else
    {
        printf("没有找到该学生\n");
        printf("添加前：\n");
        PrintList(first);
        AddNode(first, id);
        printf("添加后：\n");
        PrintList(first);
    }
    return 0;
}

Student *InitList()
{
    Student *first = (Student *)malloc(sizeof(Student));
    if (first == NULL)
        ErrorHandler(1);
    if (first != NULL)
    {
        first->next = NULL;
    }
    else
    {
        first = NULL;
    }
    return first;
}

// 从键盘读入学生信息，输入-1停止
void CreateList(Student *first)
{
    Student *p = first;
    Student *q;
    long long num;

    printf("请输入学号：");
    scanf("%lld", &num);

    while (num != -1)
    {
        q = (Student *)malloc(sizeof(Student));
        if (q == NULL)
            ErrorHandler(1);
        q->id = num;

        printf("请输入性别(M/F): ");
        getchar(); // 读取回车
        scanf("%c", &(q->sex));

        printf("请输入姓名：");
        scanf("%s", q->name);

        printf("请输入成绩：");
        scanf("%f", &(q->score));

        p->next = q;
        p = q;

        printf("请输入学号：");
        scanf("%lld", &num);
    }
    p->next = NULL;
}

// 从键盘输入一个学生学号，在单链表中查询，返回该节点前一个结点的指针
Student *FindPrevious(Student *first, long long id)
{
    Student *p = first;
    while (p->next != NULL)
    {
        if (p->next->id == id)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 传入一个节点指针，删除该节点的下一个节点
void DeleteNode(Student *p)
{
    Student *q = p->next;
    if (q == NULL)
        ErrorHandler(2);
    p->next = q->next;
    free(q);
}

// 传入头指针和学号，将该学生添加到链表末尾
void AddNode(Student *first, long long id)
{
    Student *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Student *q = (Student *)malloc(sizeof(Student));
    if (q == NULL)
        ErrorHandler(1);
    q->id = id;
    strcpy(q->name, "AddStudent");
    q->score = 0;
    q->sex = 'M';
    p->next = q;
}

void PrintList(Student *first)
{
    Student *p = first->next;
    do
    {
        printf("姓名: %s\n", p->name);
        printf("性别: %c\n", p->sex);
        printf("学号：%lld\n", p->id);
        printf("成绩: %.2f\n", p->score);
        printf("\n");
        p = p->next;
    } while (p != NULL);
}

void ErrorHandler(int error_code)
{
    switch (error_code)
    {
    case 1:
        printf("内存分配失败\n");
        exit(1);
    case 2:
        printf("删除失败\n");
        exit(2);
    default:
        break;
    }
}