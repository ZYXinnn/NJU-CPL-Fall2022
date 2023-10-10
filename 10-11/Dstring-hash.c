/*
 * @Author: ZYXin
 * @Date: 2022-12-17 10:18:01
 * @LastEditTime: 2023-03-14 15:27:26
 * @FilePath: \c\10-11\Dstring-hash.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n1, n2;
typedef struct Node
{
    char str[1005];
    struct Node *next;
} Node;
Node **data;
int hash(char *s)
{
    int len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++)
        ret = (ret + s[i] * (i + 1)) % 35000;
    return ret;
}
Node *nodeinit(char *s, Node *head)
{
    Node *x = (Node *)malloc(sizeof(Node));
    Node *point = head;
    x->next = NULL;
    strcpy(x->str, s);
    if (head == NULL)
    {
        head = x;
        point = x;
    }
    else
    {
        while (point->next != NULL)
            point = point->next;
        point->next = x;
    }
    return head;
}
void insert(Node **data, char *s)
{
    int strhash = hash(s);
    int i = strhash % (2 * n1 + 6);
    data[i] = nodeinit(s, data[i]);
    return;
}
int search(Node **data, char *str)
{
    int strhash = hash(str);
    int i = strhash % (2 * n1 + 6);
    Node *p = data[i];
    while (p != NULL)
    {
        if (strcmp(str, p->str) == 0)
            return 1;
        else
            p = p->next;
    }
    return 0;
}
int main()
{
    char str[1003];
    scanf("%d%d", &n1, &n2);
    data = (Node **)calloc(2 * n1 + 6, sizeof(Node *));
    for (int i = 1; i <= n1; i++)
    {
        scanf("%s", str);
        insert(data, str);
    }
    for (int i = 1; i <= n2; i++)
    {
        scanf("%s", str);
        if (search(data, str) == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}