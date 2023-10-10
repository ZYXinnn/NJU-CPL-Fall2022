/*
 * @Author: ZYXin
 * @Date: 2022-12-27 11:45:35
 * @LastEditTime: 2022-12-27 12:01:08
 * @FilePath: \c\2021-exam\Asorted.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int arr[12][1002], t, n, m;
void sort(int x, int ti)
{
    arr[ti][0] = arr[ti][x];
    for (int i = x; i > 0; i--)
        arr[ti][i] = arr[ti][i - 1];
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
        for (int j = 1; j <= m; j++)
        {
            int p;
            scanf("%d", &p);
            sort(p, i);
        }
        int r = 0;
        for (int j = 1; j <= n - 1; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                r = 1;
                break;
            }
        }
        if (r == 0)
            printf("I love C programming language\n");
        else if (r == 1)
            printf("mayi is a good teacher\n");
    }
    return 0;
}