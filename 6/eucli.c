/*
 * @Author: ZYXin
 * @Date: 2023-02-20 15:15:44
 * @LastEditTime: 2023-02-20 15:25:50
 * @FilePath: \c\6\eucli.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int eucli(int a, int b)
{
    int r = a % b;
    if (r == 0)
        return b;
    else
        return eucli(b, r);
}
int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = eucli(a, b);
    printf("两数最大公因数为：%d", c);
    return 0;
}