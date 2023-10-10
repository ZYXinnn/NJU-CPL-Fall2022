#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    char a1[20], b1[20];
    scanf("%s %d %d %s %d %d %d", &a1, &a, &b, &b1, &c, &d, &e);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", b1, a1, a, c, d, e, b);
    return 0;
}