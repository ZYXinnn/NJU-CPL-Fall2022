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
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    arr1[i] = j - i + 1;
                    break;
                }
                else
                    arr1[i] = j - i + 2;
            }
            if (i == n - 1)
                arr1[i] = 2;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (b < arr1[i])
        {
            b = arr1[i];
            c = i;
        }
    }
    for (int j = c; j <= c + b - 1; j++)
    {
        if (c == 1)
        {
            break;
        }
        if (j <= c + b - 2)
        {
            if (arr[c - 1] < arr[j] && arr[c - 1] > arr[j + 1])
            {
                p = arr[c - 1];
                arr[c - 1] = arr[j];
                arr[j] = p;
                break;
            }
        }
        else if (arr[c - 1] < arr[j])
        {
            p = arr[c - 1];
            arr[c - 1] = arr[j];
            arr[j] = p;
        }
    }
    for (int j = n; j > n - (b / 2); j--)
    {
        p = arr[j];
        arr[j] = arr[2 * n - b + 1 - j];
        arr[2 * n - b + 1 - j] = p;
    }
    for (int j = 1; j <= n; j++)
        printf("%d ", arr[j]);
    return 0;
}