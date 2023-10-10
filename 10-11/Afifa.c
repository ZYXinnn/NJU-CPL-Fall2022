/*
 * @Author: ZYXin
 * @Date: 2022-12-09 23:02:32
 * @LastEditTime: 2022-12-10 00:05:54
 * @FilePath: \c\10-11\fifa.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n;
char o[30];
struct Member
{
    int jinggong;
    int fangshou;
    int zhanshu;
};
struct Team
{
    // int type;
    char p[30];
    struct Member member[11];
    int jg;
    int fs;
    int zs;
};
struct Team te[1005];

int equal(int a, int b)
{
    int x = 0;
    if (b == 1)
    {
        for (int i = 0; i <= 10; i++)
            x += te[a].member[i].jinggong;
    }
    if (b == 2)
    {
        for (int i = 0; i <= 10; i++)
            x += te[a].member[i].fangshou;
    }
    if (b == 3)
    {
        for (int i = 0; i <= 10; i++)
            x += te[a].member[i].zhanshu;
    }
    return x;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%s", te[i].p);
        for (int j = 0; j <= 10; j++)
        {
            scanf("%s", o);
            scanf("%d", &te[i].member[j].jinggong);
            scanf("%d", &te[i].member[j].fangshou);
            scanf("%d", &te[i].member[j].zhanshu);
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        te[i].jg = equal(i, 1);
        te[i].fs = equal(i, 2);
        te[i].zs = equal(i, 3);
    }
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2; j++)
        {
            if (te[j].jg < te[j + 1].jg)
            {
                struct Team t;
                t = te[j + 1];
                te[j + 1] = te[j];
                te[j] = t;
            }
        }
    }
    for (int i = 0; i <= n - 1; i++)
        printf("%s ", te[i].p);
    printf("\n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2; j++)
        {
            if (te[j].fs < te[j + 1].fs)
            {
                struct Team t;
                t = te[j + 1];
                te[j + 1] = te[j];
                te[j] = t;
            }
        }
    }
    for (int i = 0; i <= n - 1; i++)
        printf("%s ", te[i].p);
    printf("\n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2; j++)
        {
            if (te[j].zs < te[j + 1].zs)
            {
                struct Team t;
                t = te[j + 1];
                te[j + 1] = te[j];
                te[j] = t;
            }
        }
    }
    for (int i = 0; i <= n - 1; i++)
        printf("%s ", te[i].p);
    return 0;
}