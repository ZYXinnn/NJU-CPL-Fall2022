/*
 * @Author: ZYXin
 * @Date: 2022-12-27 11:19:19
 * @LastEditTime: 2023-02-20 16:01:44
 * @FilePath: \c\2021-exam\Bbsearch.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, q, arr[1000004], t;
int bs(int left, int right)
{
    if (left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (left < right)
        {
            if (arr[mid] > t)
                return bs(left, mid);
            else if (arr[mid] < t)
                return bs(mid + 1, right);
            else if (arr[mid] == t)
                return mid;
        }
        else if (left == right)
        {
            if (arr[mid] == t)
                return mid;
            else
                return -1;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &t);
        printf("%d\n", bs(0, n - 1));
    }
    return 0;
}