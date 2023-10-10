/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-13 10:17:05
 * @FilePath: \c\7\Frotate.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a, b, c, x = 0, y = 0, xx = 0, yy = 0, m, n, p;
char str[1000];
void M(char q)
{
    if (q == 'W')
    {
        if (6 - m - n == 3)
            x -= c;
        else if (6 - m - n == 2)
            x -= b;
        else if (6 - m - n == 1)
            x -= a;
        if (m == 1)
            xx -= a;
        else if (m == 2)
            xx -= b;
        else if (m == 3)
            xx -= c;
        m = 6 - m - n;
    }
    if (q == 'S')
    {
        if (6 - m - n == 3)
            xx += c;
        else if (6 - m - n == 2)
            xx += b;
        else if (6 - m - n == 1)
            xx += a;
        if (m == 1)
            x += a;
        else if (m == 2)
            x += b;
        else if (m == 3)
            x += c;
        m = 6 - m - n;
    }
    if (q == 'A')
    {
        if (6 - m - n == 3)
            y -= c;
        else if (6 - m - n == 2)
            y -= b;
        else if (6 - m - n == 1)
            y -= a;
        if (n == 1)
            yy -= a;
        else if (n == 2)
            yy -= b;
        else if (n == 3)
            yy -= c;
        n = 6 - m - n;
    }
    if (q == 'D')
    {
        if (6 - m - n == 3)
            yy += c;
        else if (6 - m - n == 2)
            yy += b;
        else if (6 - m - n == 1)
            yy += a;
        if (n == 1)
            y += a;
        else if (n == 2)
            y += b;
        else if (n == 3)
            y += c;
        n = 6 - m - n;
    }
}
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", str);
    x = 0;
    xx = a;
    y = 0;
    yy = b;
    m = 1;
    n = 2;
    p = strlen(str);
    for (int i; i <= p; i++)
        M(str[i]);
    printf("%d %d %d %d", x, xx, y, yy);
    return 0;
}