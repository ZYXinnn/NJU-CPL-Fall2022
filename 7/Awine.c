/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-12 20:44:52
 * @FilePath: \c\7\Awine.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, l, arr[10001], arr1[10001], count, d = 0;
int MAX()
{
    int max = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            b = i;
        }
    }
    arr[b] = 0;
    for (int i = 1;; i++)
    {
        if (count > 0 && arr1[b] > 0)
        {
            c += max;
            count--;
            arr1[b]--;
        }
        else
            break;
    }
    return c;
}
int main()
{
    scanf("%d%d", &n, &l);
    count = l;
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr1[i]);
    for (;;)
    {
        if (count > 0)
            d += MAX();
        else
            break;
    };
    printf("%d", d);
    return 0;
}