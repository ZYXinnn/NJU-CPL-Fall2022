/*
 * @Author: ZYXin
 * @Date: 2022-11-25 22:55:07
 * @LastEditTime: 2022-11-26 10:13:03
 * @FilePath: \c\9\Bstringcat.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, a, b;
void mystrcat(char *c, char *d)
{
    int s = 0, l;
    for (int i = 1; i <= a; i++)
    {
        s = 0;
        if (*(c + i - 1) == *d)
        {
            for (int j = 0; j <= a - i; j++)
            {
                if (*(c + i - 1 + j) != *(d + j))
                {
                    s = 1;
                    break;
                }
            }
            if (s == 0)
            {
                l = i;
                break;
            }
        }
    }
    printf("%.*s", l - 1, c);
    printf("%s\n", d);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char *p = (char *)malloc(1006 * sizeof(char));
        char *q = (char *)malloc(1006 * sizeof(char));
        scanf("%s%s", p, q);
        a = strlen(p);
        b = strlen(q);
        mystrcat(p, q);
        free(p);
        free(q);
    }
    return 0;
}