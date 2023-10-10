/*
 * @Author: ZYXin
 * @Date: 2022-11-27 12:29:47
 * @LastEditTime: 2022-12-05 19:32:03
 * @FilePath: \c\9\Atokenizer.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int *q, n = 0, m = 0;
char *p1 = "const", *p2 = "int", *p3 = "float", *p4 = "double", *p5 = "long", *p6 = "static", *p7 = "void", *p8 = "goto", *p9 = "char", *p10 = "extern", *p11 = "return", *p12 = "break", *p13 = "enum", *p14 = "struct", *p15 = "typedef", *p16 = "union";
char *q1 = "+", *q2 = "-", *q3 = "*", *q4 = "/", *q5 = "=", *q6 = "==", *q7 = "!=", *q8 = ">=", *q9 = "<=", *q10 = ">", *q11 = "<";
int process(char *p)
{
    int a, count = 0;
    a = strlen(p);
    for (int i = 1; i <= a; i++)
    {
        if (*(p + i - 1) == '.')
            count++;
    }
    if (count == 0)
    {
        if (strcmp(p, p1) == 0 || strcmp(p, p2) == 0 || strcmp(p, p3) == 0 || strcmp(p, p4) == 0 || strcmp(p, p5) == 0 || strcmp(p, p6) == 0 || strcmp(p, p7) == 0 || strcmp(p, p8) == 0 || strcmp(p, p9) == 0 || strcmp(p, p10) == 0 || strcmp(p, p11) == 0 || strcmp(p, p12) == 0 || strcmp(p, p13) == 0 || strcmp(p, p14) == 0 || strcmp(p, p15) == 0 || strcmp(p, p16) == 0)
            return 1;
        else if (strcmp(p, q1) == 0 || strcmp(p, q2) == 0 || strcmp(p, q3) == 0 || strcmp(p, q4) == 0 || strcmp(p, q5) == 0 || strcmp(p, q6) == 0 || strcmp(p, q7) == 0 || strcmp(p, q8) == 0 || strcmp(p, q9) == 0 || strcmp(p, q10) == 0 || strcmp(p, q11) == 0)
            return 4;
        else if ((int)*p == 95 || ((int)*p >= 97 && (int)*p <= 122) || ((int)*p >= 65 && (int)*p <= 90))
            return 5;
        else if (((int)*p >= 48 && (int)*p <= 57))
        {
            for (int i = 1; i <= a; i++)
            {
                if (*(p + i - 1) >= 65)
                    return 6;
            }
            return 2;
        }
        else
            return 6;
    }
    else if (count == 1)
        return 3;
    else
        return 6;
}
int main()
{
    q = (int *)malloc(4096);
    char *s = (char *)malloc(4096);
    while (scanf("%s", s) != EOF)
    {
        char *position = strchr(s, ';'); // if there's no ';' in s, it returns NULL.
        if (position == NULL)
        {
            *(q + n) = process(s);
            n++;
        }
        else
        {
            if (*(position - 1) != '\0')
            {
                *position = '\0';
                *(q + n) = process(s);
                n++;
                *(q + n) = 7;
                n++;
                if (*(position + 1) != '\0')
                {
                    *(q + n) = process(position + 1);
                    n++;
                }
            }
            else
            {
                *position = '\0';
                *(q + n) = 7;
                n++;
                if (*(position + 1) != '\0')
                {
                    *(q + n) = process(position + 1);
                    n++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (*(q + i - 1) == 6)
        {
            printf("Compile Error");
            m = 1;
            break;
        }
    }
    if (m != 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (*(q + i - 1) == 1)
                printf("reserved ");
            if (*(q + i - 1) == 2)
                printf("integer ");
            if (*(q + i - 1) == 3)
                printf("float ");
            if (*(q + i - 1) == 4)
                printf("operator ");
            if (*(q + i - 1) == 5)
                printf("variable ");
            if (*(q + i - 1) == 7)
                printf("\n");
        }
    }
    return 0;
}