/*
 * @Author: ZYXin
 * @Date: 2022-11-18 18:04:18
 * @LastEditTime: 2022-11-21 14:40:50
 * @FilePath: \c\8\Ainterpreter copy.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int *x = (int *)malloc(sizeof x);
    scanf("%x", x);
    printf("%d\n%u\n%f\n%.3e", *x, *x, *(float *)x, *(float *)x);
    return 0;
}