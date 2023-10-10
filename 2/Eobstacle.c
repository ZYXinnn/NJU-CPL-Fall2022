#include <stdio.h>

int main()
{
    int a, b, d, e, f, x1, y1, x2, y2, x3, y3, c;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    d = (y1 == y2) && (y3 != y1);
    a = (x1 < x3) && (x3 < x2);
    b = (x2 < x3) && (x3 < x1);
    e = (y1 < y3) && (y3 < y2);
    f = (y2 < y3) && (y3 < y1);
    if (x1 != x2)
    {
        if (y1 != y2 || d != 0)
        {
            if (x1 > x2)
            {
                if (y1 >= y2)
                    c = x1 - x2 + y1 - y2;
                else
                    c = x1 - x2 + y2 - y1;
            }
            else if (x1 < x2)
            {
                if (y1 >= y2)
                    c = x2 - x1 + y1 - y2;
                else
                    c = x2 - x1 + y2 - y1;
            }
            printf("%d\n", c);
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
            else if (x1 != x3 && y2 != y3)
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
        else if (y1 == y2 && y3 == y2)
        {
            if (a != 0 && b == 0)
            {
                c = x2 - x1 + 2;
                printf("%d\n", c);
                printf("D");
                while (x2 > x1)
                {
                    printf("R");
                    x1++;
                }
                printf("U");
            }
            else if (a == 0 && b != 0)
            {
                c = x1 - x2 + 2;
                printf("%d\n", c);
                printf("D");
                while (x1 > x2)
                {
                    printf("L");
                    x1--;
                }
                printf("U");
            }
            else if (a == 0 && b == 0)
            {
                if (x1 < x2)
                {
                    c = x2 - x1;
                    printf("%d\n", c);
                    while (x1 < x2)
                    {
                        printf("R");
                        x1++;
                    }
                }
                else if (x1 > x2)
                {
                    c = x1 - x2;
                    printf("%d\n", c);
                    while (x1 > x2)
                    {
                        printf("L");
                        x1--;
                    }
                }
            }
        }
    }
    else if (x1 == x2)
    {
        if (x3 != x1)
        {
            if (y1 < y2)
            {
                c = y2 - y1;
                printf("%d\n", c);
                while (y1 < y2)
                {
                    printf("U");
                    y1++;
                }
            }
            else if (y1 > y2)
            {
                c = y1 - y2;
                printf("%d\n", c);
                while (y1 > y2)
                {
                    printf("D");
                    y1--;
                }
            }
        }
        else if (x3 == x1)
        {
            if (f != 0 && e == 0)
            {
                c = y1 - y2 + 2;
                printf("%d\n", c);
                printf("L");
                while (y1 > y2)
                {
                    printf("D");
                    y1--;
                }
                printf("R");
            }
            else if (e != 0 && f == 0)
            {
                c = y2 - y1 + 2;
                printf("%d\n", c);
                printf("L");
                while (y1 < y2)
                {
                    printf("U");
                    y1++;
                }
                printf("R");
            }
            else if (e == 0 && f == 0)
            {
                if (y1 < y2)
                {
                    c = y2 - y1;
                    printf("%d\n", c);
                    while (y1 < y2)
                    {
                        printf("U");
                        y1++;
                    }
                }
                else if (y1 > y2)
                {
                    c = y1 - y2;
                    printf("%d\n", c);
                    while (y1 > y2)
                    {
                        printf("D");
                        y1--;
                    }
                }
            }
        }
    }
    return 0;
}