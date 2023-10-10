/*
 * @Author: ZYXin
 * @Date: 2022-12-10 08:19:07
 * @LastEditTime: 2022-12-10 09:14:37
 * @FilePath: \c\10-11\polynlist.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char p[12];
struct polynlist
{
    int n;
    int arr[20005];
};
int MAX(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void printp(struct polynlist x)
{
    for (int i = x.n; i >= 0; i--)
    {
        if (i == 0 && x.arr[0] == 0)
        {
            if (x.n == 0)
                printf("0");
        }
        else if (x.arr[i] > 0)
        {
            if (i == x.n)
                if (i == 1)
                {
                    if (x.arr[i] != 1)
                        printf("%d%s", x.arr[i], p);
                    else
                        printf("%s", p);
                }
                else if (i == 0)
                    printf("%d", x.arr[i]);
                else
                {
                    if (x.arr[i] != 1)
                        printf("%d%s^%d", x.arr[i], p, x.n);
                    else
                        printf("%s^%d", p, x.n);
                }
            else if (i == 1)
            {
                if (x.arr[i] != 1)
                    printf("+%d%s", x.arr[1], p);
                else
                    printf("+%s", p);
            }
            else if (i == 0)
                printf("+%d", x.arr[0]);
            else
            {
                if (x.arr[i] != 1)
                    printf("+%d%s^%d", x.arr[i], p, i);
                else
                    printf("+%s^%d", p, i);
            }
        }
        else if (x.arr[i] < 0)
        {
            if (i == x.n)
                if (i == 1)
                {
                    if (x.arr[i] != -1)
                        printf("%d%s", x.arr[i], p);
                    else
                        printf("-%s", p);
                }
                else if (i == 0)
                    printf("%d", x.arr[i]);
                else
                {
                    if (x.arr[i] != -1)
                        printf("%d%s^%d", x.arr[i], p, x.n);
                    else
                        printf("-%s^%d", p, x.n);
                }
            else if (i == 1)
            {
                if (x.arr[i] != -1)
                    printf("%d%s", x.arr[1], p);
                else
                    printf("-%s", p);
            }
            else if (i == 0)
                printf("%d", x.arr[0]);
            else
            {
                if (x.arr[i] != -1)
                    printf("%d%s^%d", x.arr[i], p, i);
                else
                    printf("-%s^%d", p, i);
            }
        }
    }
    printf("\n");
    return;
};
struct polynlist p1, p2, p3, p4, p5; // 原原乘加减
int main()
{
    scanf("%d%d", &p1.n, &p2.n);
    scanf("%s", p);
    p3.n = p1.n + p2.n;
    p4.n = MAX(p1.n, p2.n);
    p5.n = p4.n;
    for (int i = p1.n; i >= 0; i--)
        scanf("%d", &p1.arr[i]);
    for (int i = p2.n; i >= 0; i--)
        scanf("%d", &p2.arr[i]);
    for (int i = p1.n; i >= 0; i--) // 乘
    {
        for (int j = p2.n; j >= 0; j--)
        {
            int x = i + j;
            p3.arr[i + j] += p1.arr[i] * p2.arr[j];
        }
    }
    for (int i = p4.n; i >= 0; i--)
    {
        p4.arr[i] = p1.arr[i] + p2.arr[i];
        p5.arr[i] = p1.arr[i] - p2.arr[i];
    }
    printp(p4);
    printp(p5);
    printp(p3);
    return 0;
}