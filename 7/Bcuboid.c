/*
 * @Author: ZYXin
 * @LastEditTime: 2022-11-21 15:40:10
 * @FilePath: \c\7\Bcuboid.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int t, arr[200];
void X(int n)
{
    int a = arr[n], b = arr[n + 1], c = arr[n + 2], count = 0, count1 = 0;
    if (c < b)
    {
        for (int i = 1; i <= c; i++)
        {
            for (int i = 1; i <= b + count; i++)
                printf("  ");
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count; i--)
                printf(" +");
            printf("\n");
            for (int i = 1; i <= b - 1 + count; i++)
                printf("  ");
            printf(" ");
            for (int i = 1; i <= a; i++)
                printf("/ ");
            for (int i = 0; i >= count; i--)
                printf("/|");
            printf("\n");
            count--;
        }
        count1 = count;
        for (int i = 1; i <= b - c; i++)
        {
            for (int i = 1; i <= b + count1; i++)
                printf("  ");
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count; i--)
                printf(" +");
            printf("\n");
            for (int i = 1; i <= b + count1 - 1; i++)
                printf("  ");
            printf(" ");
            for (int i = 1; i <= a; i++)
                printf("/ ");
            for (int i = -1; i >= count; i--)
                printf("/|");
            printf("/");
            printf("\n");
            count1--;
        }
        for (int i = 1; i <= b + count1; i++)
            printf("  ");
        for (int i = 1; i <= a; i++)
            printf("+-");
        printf("+");
        for (int i = -1; i >= count; i--)
            printf(" +");
        printf("\n");
        for (int i = 1; i <= c; i++)
        {
            for (int i = 1; i <= a; i++)
                printf("| ");
            for (int i = -1; i >= count; i--)
                printf("|/");
            printf("\n");
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count + 1; i--)
                printf(" +");
            printf("\n");
            count++;
        }
    }
    if (c >= b)
    {
        for (int i = 1; i <= b; i++)
        {
            for (int i = 1; i <= b + count; i++)
                printf("  ");
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count; i--)
                printf(" +");
            printf("\n");
            for (int i = 1; i <= b - 1 + count; i++)
                printf("  ");
            printf(" ");
            for (int i = 1; i <= a; i++)
                printf("/ ");
            for (int i = 0; i >= count; i--)
                printf("/|");
            printf("\n");
            count--;
        }
        for (int i = 1; i <= c - b; i++)
        {
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count; i--)
                printf(" +");
            printf("\n");
            for (int i = 1; i <= a; i++)
                printf("| ");
            printf("|");
            for (int i = -1; i >= count; i--)
                printf("/|");
            printf("\n");
        }
        for (int i = 1; i <= a; i++)
            printf("+-");
        printf("+");
        for (int i = -1; i >= count; i--)
            printf(" +");
        printf("\n");
        count++;
        for (int i = 1; i <= b; i++)
        {
            for (int i = 1; i <= a; i++)
                printf("| ");
            for (int i = -1; i >= count - 1; i--)
                printf("|/");
            printf("\n");
            for (int i = 1; i <= a; i++)
                printf("+-");
            printf("+");
            for (int i = -1; i >= count; i--)
                printf(" +");
            printf("\n");
            count++;
        }
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= 3 * t; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= 3 * t - 2; i += 3)
        X(i);
    return 0;
}
