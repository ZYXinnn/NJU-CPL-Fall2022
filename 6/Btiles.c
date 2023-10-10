/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-04 20:20:08
 * @FilePath: \c\6\Btiles.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int X(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    else
        return X(n - 1) + X(n - 2);
}
int main()
{
    int n, c = 0;
    scanf("%d", &n);
    c += X(n);
    printf("%d", c);
    return 0;
}