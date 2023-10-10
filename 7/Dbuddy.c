/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-17 17:50:28
 * @FilePath: \c\7\Dbuddy.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, q, a, k, id, t = 0;
char w;
int id1[10002] = {0}, arr[10002] = {0}, bu[100002], m[10002], len[10002] = {0}; //放id,A/Q,内存
void A(int c, int b)
{
    for (int i = 1; i <= k; i++)
    {
        if (c == bu[i] && len[i] == 0)
        {
            len[i] = b;
            return;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (bu[i] > c && len[i] == 0)
        {
            int x = bu[i] - c;
            k += x;
            len[i] = b;
            for (int j = k; j >= i + x + 1; j--)
            {
                bu[j] = bu[j - x];
                len[j] = len[j - x];
            }
            bu[i] = c;
            bu[i + 1] = c;
            len[i + 1] = 0;
            for (int j = i + 1; j <= i + x; j++)
            {
                bu[j] = c;
                len[j] = 0;
                c++;
            }
            return;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    bu[1] = n;
    k = 1;
    for (int i = 1; i <= q; i++)
    {
        getchar();
        scanf("%c", &w);
        if (w == 'A')
        {
            scanf("%d%d", &id1[i], &a);
            for (int j = 0;; j++)
            {
                if (a > pow(2, j) && a <= pow(2, j + 1))
                {
                    m[i] = j + 1;
                    break;
                }
                else if (a == 1)
                {
                    m[i] = 0;
                    break;
                }
            }
        }
        else if (w == 'Q')
            arr[i] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        if (arr[i] == 0)
            A(m[i], id1[i]);
        else if (arr[i] == 1)
        {
            printf("%d\n", k);
            for (int j = 1; j <= k; j++)
                printf("%d ", len[j]);
            printf("\n");
        }
    }
    return 0;
}