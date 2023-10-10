/*
 * @Author: ZYXin
 * @Date: 2022-11-27 15:26:20
 * @LastEditTime: 2022-11-27 19:22:22
 * @FilePath: \c\9\Cparse.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char *p; // p用于存放参数而x用于存放输出参数
int a = 0, w, m = 0;
int test(char *t)
{
    for (int i = 1; i <= 128; i++)
    {
        if (*(p + i - 1) == *t && *(p + i) != ':')
        {
            return 1;
        }
        else if (*(p + i - 1) == *t && *(p + i) == ':')
        {
            return 2;
        }
    }
    return 3;
}
int main()
{
    p = (char *)malloc(128);
    char *p1 = (char *)malloc(1024);
    char *q = (char *)malloc(1030);
    char *x = (char *)malloc(1024);
    memset(x, 0, 1024);
    memset(q, 0, 1024);
    scanf("%s", p);
    scanf("%s", p1);
    getchar();
    gets(q);
    for (int i = 1; i <= 1024; i++)
    {
        if (*(q + i - 1) == '-')
        {
            w = test(q + i);
            if (w == 1)
            {
                *(x + a) = *(q + i);
                a++;
                *(x + a) = '\n';
                a++;
                i += 2;
            }
            else if (w == 3)
            {
                *(x + a) = *(q + i);
                a++;
                *(x + a) = '0';
                a++;
                break;
            }
            else if (w == 2)
            {
                int k = 0;
                *(x + a) = *(q + i);
                a++;
                i++;
                *(x + a) = '=';
                a++;
                i++;
                for (int j = 1; *(q + i - 1 + j) != '\0' && *(q + i - 1 + j) != ' '; j++)
                {
                    *(x + a) = *(q + i - 1 + j);
                    a++;
                    k++;
                }
                i += k;
                *(x + a) = '\n';
                a++;
                i++;
            }
        }
    }
    for (int i = 1; i <= a; i++)
    {
        if (*(x + i - 1) == '0')
        {
            printf("%s: invalid option -- '%c'", p1, *(x + i - 2));
            m = 1;
            break;
        }
        if (*(x + i - 1) == '=' && *(x + i) == '\n')
        {
            printf("%s: option requires an argument -- '%c'", p1, *(x + i - 2));
            m = 1;
            break;
        }
    }
    if (m != 1)
        printf("%s\n%.*s", p1, a, x);
    return 0;
}