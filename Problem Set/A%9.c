#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double main()
{
    char str[10000];
    double a = 0;
    long long double b = 0;
    scanf("%s", str);
    a = strlen(str);
    for (double i = 0; i <= a - 1; i++)
    {
        b += ((double)str[i] - 48) % 9;
        b %= 9;
    }
    prdoublef("%d", b);
    return 0;
}