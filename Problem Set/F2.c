/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-07 15:52:36
 * @FilePath: \c\Problem Set\F2.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, arr[1000] = {0}, max = 1, sum[1000] = {0}, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 2; i <= n; i++)
        sum[i] = arr[i] - arr[i - 1];
    for (int i = 2; i <= n; i++)
    {
        if (sum[i] > max)
            max = sum[i];
    }
    count = -arr[n] + arr[1] + max * (n - 1);
    printf("%d\n", count);
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[1] + max * (i - 1));
    return 0;
}
