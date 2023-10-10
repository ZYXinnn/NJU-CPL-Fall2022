/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-05 09:20:07
 * @FilePath: \c\6\Ftriangle.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[1025][2049];
void X(int n, int a, int b)
{
    if (n == 1)
    {
        str[a][b] = '/';
        str[a][b + 1] = '\\';
        str[a + 1][b - 1] = '/';
        str[a + 1][b] = '_';
        str[a + 1][b + 1] = '_';
        str[a + 1][b + 2] = '\\';
    }
    else
    {
        X(n - 1, a + pow(2, n - 1), b - pow(2, n - 1));
        X(n - 1, a + pow(2, n - 1), b + pow(2, n - 1));
        X(n - 1, a, b);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = pow(2, n); i >= 1; i--)
    {
        int k = pow(2, n + 1);
        for (int j = 1; j <= k; j++)
            str[i][j] = ' ';
        k--;
    }
    X(n, 1, pow(2, n));
    // printf(" /\\ \n/__\\");
    // X(1,1,2);
    for (int i = 1; i <= pow(2, n); i++)
    {
        for (int j = 1; j <= pow(2, n + 1); j++)
            printf("%c", str[i][j]);
        printf("\n");
    }
    return 0;
}