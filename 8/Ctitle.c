/*
 * @Author: ZYXin
 * @Date: 2022-11-18 21:13:51
 * @LastEditTime: 2022-11-18 21:28:21
 * @FilePath: \c\8\Ctitle.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char *p = (char *)malloc(4096);
    gets(p);
    char *q = p;
    for (int i = 0; i <= 4095; i++)
    {
        if (*q >= 97)
            *q = *q - (char)32;
        else
        {
            if (*(q + i) == ' ' && *(q + i + 1) >= 97)
                *(q + i + 1) = *(q + i + 1) - (char)32;
            else if (*(q + i + 1) != ' ' && *(q + i + 1) != '\0' && *(q + i) != '\0' && *(q + i) != ' ' && *(q + i + 1) <= 90)
                *(q + i + 1) = (char)32 + *(q + i + 1);
        }
    }
    printf("%s", p);
    return 0;
}