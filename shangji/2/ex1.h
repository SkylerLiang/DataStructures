#ifndef __EX1_H
#define __EX1_H

typedef struct Student
{
    long long id;
    char sex;
    char name[20];
    float score;
    struct Student *next;
} Student;

Student *InitList();
void CreateList(Student *first);
Student *FindPrevious(Student *first, long long id);
void DeleteNode(Student *p);
void AddNode(Student *first, long long id);
void PrintList(Student *first);
void ErrorHandler(int error_code);

#endif