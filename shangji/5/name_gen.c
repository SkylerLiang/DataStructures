#include <stdio.h>
#include <stdlib.h>

// 随机生成名字
char *name_gen()
{
    char *name = (char *)malloc(sizeof(char) * 6);
    int i;
    for (i = 0; i < 5; i++)
    {
        name[i] = rand() % 26 + 'a';
    }
    name[5] = '\0';
    return name;
}

// 随机生成学号
int id_gen()
{
    return rand() % 100000;
}

int main()
{
    int i = 0;
    for (i = 0; i < 37; i++)
    {
        printf("%s %d ", name_gen(), id_gen());
    }
    getchar();
    return 0;
}