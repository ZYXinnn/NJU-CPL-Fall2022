/*
 * @Author: ZYXin
 * @Date: 2022-10-24 23:42:57
 * @LastEditTime: 2022-11-21 16:41:26
 * @FilePath: \c\Problem Set\C.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long int n, a = 0, b, d;
    scanf("%d", &n);
    for (int i = 1; n > a; i++)
    {
        a += i;
        d = i;
    }
    b = a - n;
    if (d % 2 == 1)
        printf("%d/%d", 1 + b, d - b);
    else if (d % 2 == 0)
        printf("%d/%d", d - b, 1 + b);
    return 0;
}