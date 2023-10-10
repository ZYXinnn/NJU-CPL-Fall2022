/*
 * @Author: ZYXin
 * @Date: 2022-11-15 21:09:35
 * @LastEditTime: 2022-11-16 20:55:12
 * @FilePath: \c\Problem Set\stack.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int arr[10001] = {0};
char st[10001];
char str[10];
#define STACK_SIZE 100
char contents[STACK_SIZE];
int top = 0;

void stack_underflow()
{
    printf("Empty\n");
}
bool is_empty(void)
{
    return top == 0;
}
void push(char i)
{
    contents[top] = i;
    top++;
}
void printstack()
{
    if (is_empty())
        stack_underflow();
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            printf("| %c |\n", contents[i]);
        }
        printf("|===|");
    }
}
void pop(void)
{
    if (is_empty())
        stack_underflow();
    else
    {
        contents[top - 1] = '\0';
        --top;
    }
}
void Top(void)
{
    if (is_empty())
        stack_underflow();
    else
        printf("%c\n", contents[top - 1]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        if (str[0] == 'p' && str[1] == 'o')
            arr[i] = 2;
        else if (str[0] == 'p' && str[1] == 'u')
        {
            n++;
            arr[i] = 1;
        }
        else if (str[0] == 't' && str[1] == 'o')
            arr[i] = 3;
        else if (str[0] == 'p' && str[1] == 'r')
            arr[i] = 4;
        else if (str[1] == '\0')
            st[i] = str[0];
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
            push(st[i + 1]);
        else if (arr[i] == 2)
            pop();
        else if (arr[i] == 3)
            Top();
        else if (arr[i] == 4)
            printstack();
    }
    return 0;
}
