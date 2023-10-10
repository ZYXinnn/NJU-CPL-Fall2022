#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[2001];
    for (int i = 1; i <= n; i++)
        arr[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j % i == 0)
            {
                if (arr[j] == 0)
                    arr[j] = 1;
                else if (arr[j] == 1)
                    arr[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
            printf("%d ", i);
    }
    return 0;
}