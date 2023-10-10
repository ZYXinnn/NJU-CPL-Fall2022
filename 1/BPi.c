#include <stdio.h>
#include <math.h>

int main()
{
    double pi1, pi2, a, b, d;
    long long int c;
    d = sqrt(163);
    c = pow(640320, 3);
    pi1 = 4 * (4 * atan(1.0 / 5.0) - atan(1.0 / 239.0));
    pi2 = log(c + 744) / d;
    printf("%.15f\n%.15f\n", pi1, pi2);
    return 0;
}