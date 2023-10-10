#include <stdio.h>

int main()
{
    int n, k, arr[1000], a, b, x, d, p, e;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    x = arr[k];
    a = 1;
    b = n;
    while (a != b)
    {
        for (int i = a; i <= n; i++)
        {
            if (arr[i] >= x || i == n)
            {
                a = i;
                break;
            }
        }
        for (int j = b; j >= 0; j--)
        {
            if (arr[j] < x || j == a)
            {
                b = j;
                break;
            }
        }
        if (a != b)
        {
            d = arr[a];
            arr[a] = arr[b];
            arr[b] = d;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < x)
            p++;
        if (arr[i] == x)
            e = i;
    }
    arr[e] = arr[p + 1];
    arr[p + 1] = x;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}