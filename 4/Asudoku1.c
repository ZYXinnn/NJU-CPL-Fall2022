#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int X(int a[10])
{
    int arr1[10] = {0};
    for (int i = 1; i <= 9; i++)
    {
        if (arr1[a[i]] == 0)
            arr1[a[i]]++;
        else
            return 0;
    }
    return 1;
}

int main()
{
    int arr[10][10], c = 1, d = 0, ar[10];
    for (int j = 1; j <= 9; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            scanf("%d", &arr[j][i]);
        }
    }
    for (int j = 1; j <= 9; j++)
    {
        c = 1;
        for (int i = 1; i <= 9; i++)
        {
            ar[i] = arr[i][j];
        }
        c = X(ar[10]);
        if (c == 0)
        {
            printf("No");
            exit;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        c = 1;
        for (int j = 1; j <= 9; j++)
        {
            ar[j] = arr[i][j];
        }
        c = X(ar[10]);
        if (c == 0)
        {
            printf("No");
            exit;
        }
    }

    return 0;
}