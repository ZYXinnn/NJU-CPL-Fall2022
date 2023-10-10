/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-04 20:55:41
 * @FilePath: \c\6\Apascal.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int X(int a, int b)
{
    if (a == 1 || b == a || b == 1)
        return 1;
    else
        return (X(a - 1, b) + X(a - 1, b - 1));
}

int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = X(a, b);
    printf("%d", c);
    return 0;
}
