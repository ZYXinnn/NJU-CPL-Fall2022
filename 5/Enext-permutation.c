#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, arr[2001], arr1[2001] = {0}, b = 0, c = 0, p;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            b = i;
            break;
        }
    }
    for (int j = b + 1; j <= n; j++)
    {
        if (j <= n - 1)
        {
            if (arr[b] < arr[j] && arr[b] > arr[j + 1])
            {
                p = arr[b];
                arr[b] = arr[j];
                arr[j] = p;
                break;
            }
        }
        else if (arr[b] < arr[j])
        {
            p = arr[b];
            arr[b] = arr[j];
            arr[j] = p;
        }
    }
    for (int j = n; j > (n + b + 1) / 2; j--)
    {
        p = arr[j];
        arr[j] = arr[n + b + 1 - j];
        arr[n + b + 1 - j] = p;
    }
    for (int j = 1; j <= n; j++)
        printf("%d ", arr[j]);
    return 0;
}
