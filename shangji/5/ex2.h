#ifndef __EX2_H__
#define __EX2_H__

typedef struct
{
    char name[6];
    int id;
} HashTable;

int hash(char *name);
int hashSearch(char *name);

#endif // __EX2_H__
