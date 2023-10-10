#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, t;
    long long int sum = 0;
    scanf("%d %d", &n, &t);
    for (int i = n; i >= 1; i--)
    {
        sum += (pow(10, i - 1)) * t * (n - i + 1);
    }
    printf("%d", sum);
    return 0;
}