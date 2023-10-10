#include <stdio.h>

int main()
{
    int l, n, a = 1, j = 1;
    long long int k = 0;
    char arr[40];
    scanf("%d%d", &l, &n);
    scanf("%s", arr);
    for (int i = 0; i <= l - 1; i++)
    {
        if (arr[l - i - 1] < 58)
        {
            if ((arr[l - i - 1] - 48) >= n)
            {
                j = l - i - 1;
            }
        }
        else
        {
            if ((arr[l - i - 1] - 55) >= n)
            {
                j = l - i - 1;
            }
        }
    }
    if (n <= 10)
    {
        if (arr[j] - 48 >= n)
            printf("Error");
        if (arr[j] - 48 < n)
        {
            for (int i = l - 1; i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    a *= n;
                }
                if (arr[l - i - 1] < 58)
                {
                    k += a * ((int)arr[l - i - 1] - 48);
                }
                else
                    k += a * ((int)arr[l - i - 1] - 55);
                ;
                a = 1;
            }
            printf("%d", k);
        }
    }
    if (n > 10)
    {
        if (arr[j] - 55 >= n)
            printf("Error");
        if (arr[j] - 55 < n)
        {
            for (int i = l - 1; i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    a *= n;
                }
                if (arr[l - i - 1] < 58)
                {
                    k += a * ((int)arr[l - i - 1] - 48);
                }
                else
                    k += a * ((int)arr[l - i - 1] - 55);
                ;
                a = 1;
            }
            printf("%d", k);
        }
    }
    return 0;
}
