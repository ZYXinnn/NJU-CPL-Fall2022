/*
 * @Author: ZYXin
 * @Date: 2022-11-16 13:04:19
 * @LastEditTime: 2023-03-03 16:49:02
 * @FilePath: \c\7\Ebrackets.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define STACK_SIZE 100000
char contents[STACK_SIZE];
char str[STACK_SIZE];
int arr[31], top = 0;
int n, k = 0, t = 1;
bool is_empty(void)
{
    return top == 0;
}
void push(char i)
{
    contents[top++] = i;
}
void pop(void)
{
    contents[top - 1] = '\0';
    top--;
}
void leftright(char i)
{
    if (i == '{' || i == '[' || i == '(')
        push(i);
    else
    {
        if (i == ']')
        {
            if (contents[top - 1] == '[')
                pop();
            else
                arr[t] = 0;
        }
        else if (i == '}')
        {
            if (contents[top - 1] == '{')
                pop();
            else
                arr[t] = 0;
        }
        else if (i == ')')
        {
            if (contents[top - 1] == '(')
                pop();
            else
                arr[t] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (; t <= n; t++)
    {
        scanf("%s", str);
        for (int k = 0; str[k] != '\0'; k++)
            leftright(str[k]);
        if (is_empty())
            arr[t] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
            printf("False\n");
        else
            printf("True\n");
    }
    return 0;
}
