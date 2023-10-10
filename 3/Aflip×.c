#include <stdio.h>
#define A(n, b) (n = n ^ 1 << b)
#define B(n, b) (n >> b & 1)

int main()
{
    int n, x = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if ((j + 1) % i == 0)
                A(x, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (B(x, i) == 1)
            printf("%d ", i + 1);
    }
    printf("%d", x);
}