#include <stdio.h>

int main()
{
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    int arr[200][200];
    int arr2[200][200];
    int arr3[200][200];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= p; k++)
            {
                arr3[j][k] += arr[j][i] * arr2[i][k];
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}