#include <stdio.h>

int main()
{
    float G, M, m, R, F;
    scanf("%e %f", &m, &R);
    G = 6.674e-11;
    M = 77.15f;
    F = G * M * m / R / R;
    printf("%.3e", F);
    return 0;
}