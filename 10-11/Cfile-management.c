/*
 * @Author: ZYXin
 * @Date: 2022-12-11 21:17:01
 * @LastEditTime: 2022-12-17 18:29:26
 * @FilePath: \c\10-11\Cfile-management1.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, p, w;
char b[12];
typedef struct node
{
    char data[12];
    struct node *prev, *next;
} *Node, node;
void Create1(Node *R)
{
    *R = NULL;
    return;
}
void Create(Node *R)
{
    char data1[12];
    scanf("%s", data1);
    *R = (node *)malloc(sizeof(node));
    strcpy((*R)->data, data1);
    Create1(&(*R)->prev);
    Create1(&(*R)->next);
    return;
}
void Remove(Node *R)
{
    if ((*R)->prev != NULL)
        Remove(&(*R)->prev);
    if ((*R)->next != NULL)
        Remove(&(*R)->next);
    memset(*R, '\0', sizeof(*R));
    *R = NULL;
    return;
}
void Value(Node R, char a[])
{
    if (R != NULL)
    {
        if (strlen(R->data) != 0)
        {
            if (strcmp(R->data, a) == 0)
            {
                if (R->prev == NULL)
                {
                    R->prev = (node *)malloc(sizeof(node));
                    strcpy(R->prev->data, b);
                    R->prev->prev = NULL;
                    R->prev->next = NULL;
                }
                else
                {
                    R->next = (node *)malloc(sizeof(node));
                    strcpy(R->next->data, b);
                    R->next->prev = NULL;
                    R->next->next = NULL;
                }
                return;
            }
            else
            {
                Value(R->prev, a);
                Value(R->next, a);
            }
        }
    }
}
void search(Node R)
{
    if (R == NULL)
    {
        return;
    }
    else if (strlen(R->data) == 0)
        return;
    else
    {
        w++;
        search(R->prev);
        search(R->next);
    }
}
void Searchvalue(Node R, char a[])
{
    if (R != NULL)
    {
        if (strlen(R->data) != 0)
        {
            if (strcmp(R->data, a) == 0)
            {
                w = 0;
                search(R);
                printf("%d\n", w);
                return;
            }
            else
            {
                Searchvalue(R->prev, a);
                Searchvalue(R->next, a);
            }
        }
    }
    else
        return;
}

void Removevalue(Node R, char a[])
{
    if (R != NULL)
    {
        if (strlen(R->data) != 0)
        {
            if (strcmp(R->data, a) == 0)
            {
                Remove(&R);
                return;
            }
            else
            {
                Removevalue(R->prev, a);
                Removevalue(R->next, a);
            }
        }
    }
    else
        return;
}
int main()
{
    scanf("%d%d", &n, &p);
    Node Tree;
    Create(&Tree);
    char a[20];
    scanf("%s", a);
    for (int i = 0; i <= n - 2; i++)
    {
        char c[12];
        scanf("%s%s", b, c);
        Value(Tree, c);
        memset(b, '\0', 12);
        memset(c, '\0', 12);
    }
    for (int i = 0; i <= p - 1; i++)
    {
        char d[12], e[12];
        scanf("%s%s", d, e);
        if (strcmp(d, "query") == 0)
            Searchvalue(Tree, e);
        else if (strcmp(d, "remove") == 0)
            Removevalue(Tree, e);
    }
    return 0;
}