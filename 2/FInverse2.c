#include <stdio.h>

int main()
{
    long long int n, k;
    char arr[1000000];
    scanf("%lld", &n);

    for (int i = 0; i <= n; i++)
    {
        scanf("%c", &arr[i]);
    }
    scanf("%lld", &k);
    for (int j = k; j > 0; j--)
    {
        printf("%c", arr[j]);
    }
    for (int l = n; l >= k + 1; l--)
    {
        printf("%c", arr[l]);
    }
    return 0;
}