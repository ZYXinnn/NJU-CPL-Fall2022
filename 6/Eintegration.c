/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-04 23:25:19
 * @FilePath: \c\6\Eintegration.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, p, arr[21];
double F(double x)
{
    double l = 0, k = 0;
    for (int i = 0; i <= n; i++)
        l += arr[i] * pow(x, i);
    k = pow(l, p);
    return k;
}
double G(double a, double b, double c) { return (4.0 * F(c) + F(a) + F(b)) / 6.0 * (b - a); }
double X(double a, double b, double i)
{
    double c = (a + b) / 2.0, d, e, f, g = (3. * a + b) / 4., h = (3.0 * b + a) / 4.;
    d = G(a, b, c);
    e = G(a, c, g);
    f = G(c, b, h);
    if (fabs(e + f - d) <= 15 * i)
        return e + f + (e + f - d) / 15.;
    else
        return X(a, c, i / 2) + X(c, b, i / 2);
}
int main()
{
    double a, b;
    double i = pow(10, -4), t;
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);
    scanf("%lf%lf", &a, &b);
    double x = 1, y = -1, z = 0;
    x = F(x);
    y = F(y);
    z = F(z);
    t = X(a, b, i);
    printf("%lf", t);
    return 0;
}