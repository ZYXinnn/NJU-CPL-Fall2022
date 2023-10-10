/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-07 14:23:17
 * @FilePath: \c\Problem Set\F.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, arr[1000] = {0}, arr1[1000] = {0}, sum[1000] = {0}, z, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int k = 1;; k++)
    {
        int c = 0;
        for (int i = 1; i <= n; i++)
            arr1[i] = arr[1] + k * (i - 1) - arr[i];
        for (int l = 1; l <= n; l++)
        {
            if (l == 1)
                sum[1] = 0;
            else
            {
                sum[l] = arr1[l];
                for (int i = 1; i <= l; i++)
                    sum[l] -= sum[i - 1];
            }
        }
        for (int j = 1; j <= n - 1; j++)
        {
            if (sum[j] < 0)
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            z = k;
            break;
        }
    }
    count = -arr[n] + arr[1] + z * (n - 1);
    printf("%d\n", count);
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[1] + z * (i - 1));
    return 0;
}