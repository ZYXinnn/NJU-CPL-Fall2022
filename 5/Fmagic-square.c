#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, arr[100][100] = {0};
    scanf("%d", &n);
    int i = 1, j = (n + 1) / 2;
    for (int k = 1; k <= n * n; k++)
    {
        arr[i][j] = k;
        if (i == 1 && j < n)
        {
            i = n;
            j++;
        }
        else if (i > 1 && j == n)
        {
            i--;
            j = 1;
        }
        else if (i == 1 && j == n)
        {
            i++;
            j = j;
        }
        else if (i > 1 && j < n)
        {
            if (arr[i - 1][j + 1] == 0)
            {
                i--;
                j++;
            }
            else if (arr[i - 1][j + 1] != 0)
            {
                i++;
                j = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}