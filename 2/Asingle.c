#include <stdio.h>

int main()
{
    int n;
    long long int b = 0;
    scanf("%d", &n);
    int a[1000005] = {0};

    for (int i = 0; i < 2 * n - 1; i++)
    {
        int index = 0;
        scanf("%d", &index);
        a[index]++;
    }

    do
    {
        b++;
    } while (a[b] != 1);
    printf("%d", b);

    return 0;
}
