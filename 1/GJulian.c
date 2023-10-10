#include <stdio.h>

int main()
{
    int year, month, day, JDN, a, y, m, jdn, w, e, r, t;
    scanf("%d %d %d", &year, &month, &day);
    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    w = (153 * m + 2) / 5;
    e = y / 4;
    r = y / 100;
    t = y / 400;

    jdn = day + w + 365 * y + e - r + t - 32045;
    printf("%d", jdn);
    return 0;
}