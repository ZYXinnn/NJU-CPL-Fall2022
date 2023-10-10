/*
 * @Author: ZYXin
 * @Date: 2022-11-18 18:04:18
 * @LastEditTime: 2023-10-10 20:13:54
 * @FilePath: \undefinedc:\Users\ZYXin\Documents\GitHub\NJU-CPL-Fall2022\8\Ainterpreter.c
 */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%x", &n);
    float* p = (float*)&n;
    printf("%d\n%u\n%.6f\n%.3e", n, n, *p, *p);
    return 0;
}