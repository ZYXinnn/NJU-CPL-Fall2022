#include <stdio.h>
#include <math.h>

int main()
{
    long int x1, y1, x2, y2, x3, y3, c, e, f, a, b;
    scanf("%ld%ld%ld%ld%ld%ld", &x1, &y1, &x2, &y2, &x3, &y3);
    a = (x1 < x3) && (x3 < x2);
    b = (x2 < x3) && (x3 < x1);
    e = (y1 < y3) && (y3 < y2);
    f = (y2 < y3) && (y3 < y1);
    if (x1 == x2 && x3 != x1)
    {
        c = abs(y2 - y1);
        printf("%ld\n", c);
        while (y1 < y2)
        {
            printf("U");
            y1++;
        }
        printf("%ld\n", c);
        while (y1 > y2)
        {
            printf("D");
            y1--;
        }
    }
    else if (x1 == x2 && x2 == x3)
    {
        if (e == 1 || f == 1)
        {
            c = abs(y1 - y2) + 2;
            printf("%ld\n", c);
            printf("R");
            while (y1 > y2)
            {
                printf("D");
                y1--;
            }
            while (y1 < y2)
            {
                printf("U");
                y1++;
            }
            printf("L");
        }
        else
        {
            c = abs(y1 - y2);
            printf("%ld\n", c);
            while (y1 < y2)
            {
                printf("U");
                y1++;
            }
            while (y1 > y2)
            {
                printf("D");
                y1--;
            }
        }
    }
    else if (y1 == y2 && y1 != y3)
    {
        c = abs(x2 - x1);
        printf("%ld\n", c);
        while (x1 < x2)
        {
            printf("R");
            x1++;
        }
        while (x1 > x2)
        {
            printf("L");
            x1--;
        }
    }
    else if (y1 == y2 && y2 == y3)
    {
        if (a == 1 || b == 1)
        {
            c = abs(x1 - x2) + 2;
            printf("%ld\n", c);
            printf("D");
            while (x1 > x2)
            {
                printf("L");
                x1--;
            }
            while (x1 < x2)
            {
                printf("R");
                x1++;
            }
            printf("U");
        }
        else
        {
            c = abs(x1 - x2);
            printf("%ld\n", c);
            while (x1 < x2)
            {
                printf("R");
                x1++;
            }
            while (x1 > x2)
            {
                printf("L");
                x1--;
            }
        }
    }
    else if (x1 != x2 && y1 != y2)
    {
        c = abs(y1 - y2) + abs(x1 - x2);
        printf("%ld\n", c);
        if (x1 == x3 || y2 == y3)
        {
            while (x1 < x2)
            {
                printf("R");
                x1++;
            }
            while (x1 > x2)
            {
                printf("L");
                x1--;
            }
            while (y1 < y2)
            {
                printf("U");
                y1++;
            }
            while (y1 > y2)
            {
                printf("D");
                y1--;
            }
        }
        else
        {
            while (y1 < y2)
            {
                printf("U");
                y1++;
            }
            while (y1 > y2)
            {
                printf("D");
                y1--;
            }
            while (x1 < x2)
            {
                printf("R");
                x1++;
            }
            while (x1 > x2)
            {
                printf("L");
                x1--;
            }
        }
    }
    return 0;
}