#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char arr[200][200];
    int ar[200][200] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = getchar();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((int)arr[i][j] != 42)
            {
                if (i == 1 && j == 1)
                {
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j + 1] == 42)
                        ar[i][j]++;
                }
                else if (i == n && j == n)
                {
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j - 1] == 42)
                        ar[i][j]++;
                }
                else if (i == 1 && j == n)
                {
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j - 1] == 42)
                        ar[i][j]++;
                }
                else if (i == n && j == 1)
                {
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j + 1] == 42)
                        ar[i][j]++;
                }
                else if (i == 1 && (j != 1 && j != n))
                {
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j - 1] == 42)
                        ar[i][j]++;
                }
                else if (i == n && (j != 1 && j != n))
                {
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j - 1] == 42)
                        ar[i][j]++;
                }
                else if (j == 1 && (i != 1 && i != n))
                {
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j + 1] == 42)
                        ar[i][j]++;
                }
                else if (j == n && (i != 1 && i != n))
                {
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j - 1] == 42)
                        ar[i][j]++;
                }
                else
                {
                    if ((int)arr[i + 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i + 1][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i][j + 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j - 1] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j] == 42)
                        ar[i][j]++;
                    if ((int)arr[i - 1][j + 1] == 42)
                        ar[i][j]++;
                }
            }
            else
            {
                ar[i][j] = 42;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ar[i][j] != 42)
                printf("%d", ar[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}