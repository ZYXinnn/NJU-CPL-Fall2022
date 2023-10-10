#include <stdio.h>

int main()
{
    int n, k, arr[1000], a, b = 1, c, x, y, d;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    a = arr[k];
    c = n;
    while (1)
    {
        for (int i = 1, j = n; i<c, j> b; i++, j--)
        {

            if (arr[b] < a)
            {
                if (arr[i] > a)
                {
                    b = i;
                    break;
                }
            }
            if (arr[c] > a)
            {
                if (arr[j] < a)
                {
                    c = j;
                    break;
                }
            }
            if (i >= j)
            {
                break;
            }
        }
        if ((arr[b] > a) && (arr[c] < a))
        {
            x = arr[c];
            arr[c] = arr[b];
            arr[b] = x;
        }
    }
    if (b >= c)
    {
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] > a)
            {
                d = i;
                break;
            }
        }
        y = arr[k];
        arr[k] = arr[d];
        arr[d] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
