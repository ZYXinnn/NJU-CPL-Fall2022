/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-04 20:11:20
 * @FilePath: \c\6\Cpoi.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[100001] = {0};
int find(int x)
{
    if (x == arr[x])
    {
        return x;
    }
    else
    {
        return find(arr[x]); //****该被替换成什么呢？
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = find(i);
        printf("%d ", arr[i]);
    }

    return 0;
}
