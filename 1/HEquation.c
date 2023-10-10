#include <stdio.h>
#include <math.h>

int main()
{
    int p, q;
    double x1, x2, x3, x4, x5;
    scanf("%d %d", &p, &q);

    if (p <= 0 && q <= 0)
    {

        x2 = -q / 2. + sqrt((q / 2.) * (q / 2.) + (p / 3.) * (p / 3.) * (p / 3.));
        x3 = -q / 2. - sqrt((q / 2.) * (q / 2.) + (p / 3.) * (p / 3.) * (p / 3.));
        x4 = cbrt(x2);
        x5 = cbrt(x3);
        x1 = x4 + x5;
        printf("%.3f", x1);
    }
    else
    {
        x2 = -q / 2. + sqrt((q / 2.) * (q / 2.) + (p / 3.) * (p / 3.) * (p / 3.));
        x3 = -q / 2. - sqrt((q / 2.) * (q / 2.) + (p / 3.) * (p / 3.) * (p / 3.));
        x4 = cbrt(-x2);
        x5 = cbrt(-x3);
        x1 = x4 + x5;
        printf("%.3f", -x1);
    }

    return 0;
}