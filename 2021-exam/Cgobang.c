/*
 * @Author: ZYXin
 * @Date: 2022-12-28 22:03:55
 * @LastEditTime: 2023-02-18 22:34:56
 * @FilePath: \c\2021-exam\Cgobang.c
 */
/*
 * @Author: ZYXin
 * @Date: 2022-12-28 22:03:55
 * @LastEditTime: 2022-12-28 23:27:00
 * @FilePath: \c\2021-exam\Cgobang.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int t;
char str[22][22];
void insertstr()
{
    for (int i = 1; i <= 20; i++)
        scanf("%s", str[i] + 1);
}
int search(char x)
{
    if (x == '*')
    {
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 17; j++)
            {
                if (str[i][j] == '*' && str[i][j + 1] == '*' && str[i][j + 2] == '*' && str[i][j + 3] == '*' && (str[i][j - 1] == '_' || str[i][j + 4] == '_'))
                    return 1;
                if (str[i][j] == '*' && str[i][j + 1] == '*' && str[i][j + 2] == '*' && str[i][j + 4] == '*' && str[i][j + 3] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i][j + 2] == '*' && str[i][j + 3] == '*' && str[i][j + 4] == '*' && str[i][j + 1] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i][j + 1] == '*' && str[i][j + 3] == '*' && str[i][j + 4] == '*' && str[i][j + 2] == '_')
                    return 1;
            }
        }
        for (int j = 1; j <= 20; j++)
        {
            for (int i = 1; i <= 17; i++)
            {
                if (str[i][j] == '*' && str[i + 1][j] == '*' && str[i + 2][j] == '*' && str[i + 3][j] == '*' && (str[i - 1][j] == '_' || str[i + 4][j] == '_'))
                    return 1;
                if (str[i][j] == '*' && str[i + 1][j] == '*' && str[i + 2][j] == '*' && str[i + 4][j] == '*' && str[i + 3][j] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 2][j] == '*' && str[i + 3][j] == '*' && str[i + 4][j] == '*' && str[i + 1][j] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 1][j] == '*' && str[i + 3][j] == '*' && str[i + 4][j] == '*' && str[i + 2][j] == '_')
                    return 1;
            }
        }
        for (int i = 1; i <= 17; i++)
        {
            for (int j = 1; j <= 17; j++)
            {
                if (str[i][j] == '*' && str[i + 1][j + 1] == '*' && str[i + 2][j + 2] == '*' && str[i + 3][j + 3] == '*' && (str[i - 1][j - 1] == '_' || str[i + 4][j + 4] == '_'))
                    return 1;
                if (str[i][j] == '*' && str[i + 1][j + 1] == '*' && str[i + 2][j + 2] == '*' && str[i + 4][j + 4] == '*' && str[i + 3][j + 3] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 3][j + 3] == '*' && str[i + 2][j + 2] == '*' && str[i + 4][j + 4] == '*' && str[i + 1][j + 1] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 1][j + 1] == '*' && str[i + 3][j + 3] == '*' && str[i + 4][j + 4] == '*' && str[i + 2][j + 2] == '_')
                    return 1;
            }
        }
        for (int i = 1; i <= 17; i++)
        {
            for (int j = 20; j >= 4; j--)
            {
                if (str[i][j] == '*' && str[i + 1][j - 1] == '*' && str[i + 2][j - 2] == '*' && str[i + 3][j - 3] == '*' && (str[i - 1][j + 1] == '_' || str[i + 4][j - 4] == '_'))
                    return 1;
                if (str[i][j] == '*' && str[i + 4][j - 4] == '*' && str[i + 2][j - 2] == '*' && str[i + 3][j - 3] == '*' && str[i + 1][j - 1] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 4][j - 4] == '*' && str[i + 2][j - 2] == '*' && str[i + 1][j - 1] == '*' && str[i + 3][j - 3] == '_')
                    return 1;
                if (str[i][j] == '*' && str[i + 4][j - 4] == '*' && str[i + 3][j - 3] == '*' && str[i + 1][j - 1] == '*' && str[i + 2][j - 2] == '_')
                    return 1;
            }
        }
        return -1;
    }
    else if (x == '#')
    {
        int num = 0;
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 17; j++)
            {
                if (str[i][j] == '#' && str[i][j + 1] == '#' && str[i][j + 2] == '#' && str[i][j + 3] == '#')
                {
                    if (str[i][j - 1] == '_')
                        num++;
                    if (str[i][j + 4] == '_')
                        num++;
                }
                if (str[i][j] == '#' && str[i][j + 1] == '#' && str[i][j + 2] == '#' && str[i][j + 4] == '#' && str[i][j + 3] == '_')
                    num++;
                if (str[i][j] == '#' && str[i][j + 4] == '#' && str[i][j + 2] == '#' && str[i][j + 3] == '#' && str[i][j + 1] == '_')
                    num++;
                if (str[i][j] == '#' && str[i][j + 4] == '#' && str[i][j + 1] == '#' && str[i][j + 3] == '#' && str[i][j + 2] == '_')
                    num++;
            }
        }
        for (int j = 1; j <= 20; j++)
        {
            for (int i = 1; i <= 17; i++)
            {
                if (str[i][j] == '#' && str[i + 1][j] == '#' && str[i + 2][j] == '#' && str[i + 3][j] == '#')
                {
                    if (str[i - 1][j] == '_')
                        num++;
                    if (str[i + 4][j] == '_')
                        num++;
                }
                if (str[i][j] == '#' && str[i + 1][j] == '#' && str[i + 2][j] == '#' && str[i + 4][j] == '#' && str[i + 3][j] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 4][j] == '#' && str[i + 2][j] == '#' && str[i + 3][j] == '#' && str[i + 1][j] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 1][j] == '#' && str[i + 4][j] == '#' && str[i + 3][j] == '#' && str[i + 2][j] == '_')
                    num++;
            }
        }
        for (int i = 1; i <= 17; i++)
        {
            for (int j = 1; j <= 17; j++)
            {
                if (str[i][j] == '#' && str[i + 1][j + 1] == '#' && str[i + 2][j + 2] == '#' && str[i + 3][j + 3] == '#')
                {
                    if (str[i - 1][j - 1] == '_')
                        num++;
                    if (str[i + 4][j + 4] == '_')
                        num++;
                }
                if (str[i][j] == '#' && str[i + 1][j + 1] == '#' && str[i + 2][j + 2] == '#' && str[i + 4][j + 4] == '#' && str[i + 3][j + 3] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 4][j + 4] == '#' && str[i + 2][j + 2] == '#' && str[i + 3][j + 3] == '#' && str[i + 1][j + 1] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 4][j + 4] == '#' && str[i + 1][j + 1] == '#' && str[i + 3][j + 3] == '#' && str[i + 2][j + 2] == '_')
                    num++;
            }
        }
        for (int i = 1; i <= 17; i++)
        {
            for (int j = 20; j >= 4; j--)
            {
                if (str[i][j] == '#' && str[i + 1][j - 1] == '#' && str[i + 2][j - 2] == '#' && str[i + 3][j - 3] == '#')
                {
                    if (str[i - 1][j + 1] == '_')
                        num++;
                    if (str[i + 4][j - 4] == '_')
                        num++;
                }
                if (str[i][j] == '#' && str[i + 1][j - 1] == '#' && str[i + 2][j - 2] == '#' && str[i + 4][j - 4] == '#' && str[i + 3][j - 3] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 4][j - 4] == '#' && str[i + 2][j - 2] == '#' && str[i + 3][j - 3] == '#' && str[i + 1][j - 1] == '_')
                    num++;
                if (str[i][j] == '#' && str[i + 4][j - 4] == '#' && str[i + 1][j - 1] == '#' && str[i + 3][j - 3] == '#' && str[i + 2][j - 2] == '_')
                    num++;
            }
        }
        return num;
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a = 0;
        insertstr();
        a = search('*');
        if (a == 1)
            printf("Lose\n");
        else if (a == -1)
        {
            a = search('#');
            if (a >= 2)
                printf("Win\n");
            else
                printf("Not Sure\n");
        }
    }
    return 0;
}