#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int p, q, r, a, b, c, d = 1, e, f, g, h = 0;
    scanf("%d%d%d", &p, &q, &r);
    for (int i = 2; i <= 40; i++)
    {
        e = p / 10 < i && p % 10 < i;
        f = q / 10 < i && q % 10 < i;
        g = r / 10 < i && r % 10 < i;
        h = e && f && g;
        a = p % 10 + (p / 10) * i;
        b = q % 10 + (q / 10) * i;
        c = r % 10 + (r / 10) * i;
        if (a * b == c && h == 1)
        {
            d = i;
            break;
        }
    }
    if (d > 1)
        printf("%d", d);
    else
        printf("0");
    return 0;
}