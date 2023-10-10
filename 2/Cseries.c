#include <stdio.h>
#include <math.h>

int main()
{
    int n, i = 0;
    float x;
    double y;
    scanf("%f %d", &x, &n);
    do
    {
        y = y + pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        i++;
    } while (i <= n);
    printf("%.10lf\n", 4 * y);
    return 0;
}