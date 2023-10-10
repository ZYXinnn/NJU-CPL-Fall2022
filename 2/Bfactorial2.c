#include <stdio.h>

int main()
{
    int n, i;
    long long int x = 1, y = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        x = x * i % 1000000007;
        y = y + x % 1000000007;
    }
    printf("%d\n", y % 1000000007);
    return 0;
}