/*
 * @Author: ZYXin
 * @Date: 2022-11-18 18:04:18
 * @LastEditTime: 2022-11-29 22:42:39
 * @FilePath: \c\8\Ainterpreter.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%x", &n);
    int *q = (int *)&n;
    float *p = (float *)&n;
    printf("%d\n%u\n%.6f\n%.3e", *q, *q, *p, *p);
    return 0;
}