#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int X(int x)
{
    int flag = 1;
    for (int i = 2; i <= sqrt(x + 0.5); i++)
    {
        if (x % i == 0)
        {
            flag = 0;
        }
    }
    return flag;
}

int main()
{
    int n, b, c, count = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int j;
        if (i <= 9)
            j = i;
        else if (i >= 10 && i <= 99)
            j = i / 10 + i % 10 * 10;
        else if (i >= 100 && i <= 999)
            j = i / 100 + 10 * ((i / 10) % 10) + 100 * (i % 10);
        else if (i == 1000)
            j = 1;
        b = X(i);
        c = X(j);
        if (b == 1 && c == 1)
            count++;
    }
    printf("%d", count);
    return 0;
}