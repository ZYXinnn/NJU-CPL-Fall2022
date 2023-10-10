#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *MAX(int *arr, int n)
{
    int p;
    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            p = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = p;
        }
    }
    return arr;
}

int main()
{
    int n, m, k, arr[10000], arr1[10000], arr2[10000] = {0}, a = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &arr[i], &arr1[i]);
    m++;
    for (int i = 1; i <= n; i++)
    {
        if (arr1[i] == 1)
            arr2[i] = arr[i] * m;
        if (arr1[i] == 0)
            arr2[i] = arr[i];
    }
    for (int i = n; i >= 1; i--)
        *arr2 = MAX(arr2, i);
    for (int i = n; i > n - k; i--)
        a += arr2[i];
    printf("%d", a);
    return 0;
}