/*
 * @Author: ZYXin
 * @Date: 2022-11-18 19:57:42
 * @LastEditTime: 2022-11-21 14:21:39
 * @FilePath: \c\8\Bsubstr.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int z = 1;
    char *p = (char *)malloc(100003 * sizeof(char));
    char *q = (char *)malloc(100003 * sizeof(char));
    scanf("%s%s", p, q);
    char *a = p;
    char *b = q;
    char *x = p;
    char *y = q;
    int j = 0;
    while (*(x + j) != '\0')
        j++;
    int l = 0;
    while (*(y + l) != '\0')
        l++;
    for (int t = 0; t <= j - l; t++)
    {
        for (int r = 0; r <= l - 1; r++)
        {
            if (*(b + r) != *(a + t + r))
            {
                z = 0;
                break;
            }
            else
                z = 1;
        }
        if (z == 1)
            printf("%d ", t);
    }
    return 0;
}