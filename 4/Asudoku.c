#include <stdio.h>

int main()
{
    int arr[10][10], c = 0, d = 0;
    for (int j = 1; j <= 9; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            scanf("%d", &arr[j][i]);
        }
    }
    for (int j = 1; j <= 9; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (arr[j][i] > 9)
            {
                c = -1;
            };
        }
    }
    if (c == -1)
    {
        printf("NO");
    }
    else
    {
        c = 0;
        for (int j = 1; j <= 9; j++)
        {
            int ar[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
            for (int i = 1; i <= 9; i++)
            {
                if (ar[arr[j][i]] == 1)
                    ar[arr[j][i]]--;
                else
                {
                    c = c - 1;
                    break;
                }
            }
            c++;
        }
        if (c == 9)
        {
            for (int k = 1, i = 1; k <= 7; k += 3)
            {
                int ar[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                for (int j = k; j <= k + 2; j++)
                {
                    for (int h = i; h <= i + 2; h++)
                    {
                        if (ar[arr[j][h]] == 1)
                            ar[arr[j][h]]--;
                        else
                        {
                            d = d - 1;
                            break;
                        }
                    }
                    d++;
                }
                i += 3;
            }
            if (d == 9)
                printf("YES");
            else
                printf("NO");
        }
        else
        {
            printf("NO");
        }
        return 0;
    }
}