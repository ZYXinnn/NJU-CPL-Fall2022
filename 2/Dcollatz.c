#include <stdio.h>

int main()
{
    int a, b;
    long int i = 0;
    scanf("%d", &a);
    b = a;
    do
    {
        if (a % 2 == 1 && a != 1)
        {
            a = 3 * a + 1;
            i++;
            if (b > a)
                b = b;
            else
                b = a;
            ;
        }
        if (a % 2 == 0)
        {
            a = a / 2;
            i++;
            b = b;
        }
    } while (a != 1);
    printf("%d %d", i, b);
    return 0;