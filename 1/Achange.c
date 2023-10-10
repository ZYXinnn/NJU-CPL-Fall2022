#include <stdio.h>

int main()
{
    int a, a1, a2, a3, a4, a5;
    scanf("%d", &a);
    a1 = a / 50;
    a2 = a % 50 / 20;
    a3 = a % 50 % 20 / 10;
    a4 = a % 50 % 20 % 10 / 5;
    a5 = a % 5;
    printf("%d\n%d\n%d\n%d\n%d\n", a1, a2, a3, a4, a5);
    return 0;
}