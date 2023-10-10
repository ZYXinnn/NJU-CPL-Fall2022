/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-04 20:42:23
 * @FilePath: \c\6\Dmax.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int arr[100001] = {0};
int n;
int X(int a, int x, int y)
{
    if (y == 1)
    {
        if (x == 1)
            return 1;
        else if (arr[a] > arr[x - 1])
            return X(a, x - 1, 1);
        else
            return x;
    }
    if (y == 2)
    {
        if (x == n)
            return n;
        else if (arr[a] > arr[x + 1])
            return X(a, x + 1, 2);
        else
            return x;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", X(i, i, 1), X(i, i, 2));
    return 0;
}
