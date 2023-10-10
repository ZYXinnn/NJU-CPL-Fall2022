/*
 * @Author: ZYXin
 * @Date: 2022-11-14 14:09:37
 * @LastEditTime: 2022-11-14 18:55:08
 * @FilePath: \c\7\Cpour.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int va, vb, vc, a, b, c, a0, b0, c0;
int k, t = 0;
void X(long long int x, long long int y, long long int z, int n)
{
    if (a + b + c < a0 + b0 + c0)
        return;
    if (x == a0 && y == b0 && z == c0)
    {
        t = 1;
        return;
    }
    if (t == 1)
        return;
    else if (n > 0)
    {
        if (vb <= x + y)
            X(0, vb, z, n - 1);
        else
            X(0, x + y, z, n - 1);
        if (vc <= x + z)
            X(0, y, vc, n - 1);
        else
            X(0, y, x + z, n - 1);
        if (va <= x + y)
            X(va, 0, z, n - 1);
        else
            X(x + y, 0, z, n - 1);
        if (vc <= y + z)
            X(x, 0, vc, n - 1);
        else
            X(x, 0, y + z, n - 1);
        if (va <= x + z)
            X(va, y, 0, n - 1);
        else
            X(x + z, y, 0, n - 1);
        if (vb <= y + z)
            X(x, vb, 0, n - 1);
        else
            X(x, y + z, 0, n - 1);
    }
}
int main()
{
    scanf("%d%lld%lld%lld%lld%lld%lld%lld%lld%lld", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
    X(a, b, c, k);
    if (t == 0)
        printf("No");
    else
        printf("Yes");
    return 0;
}