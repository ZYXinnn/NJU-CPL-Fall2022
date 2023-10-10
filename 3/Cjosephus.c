/*
 * @Author: ZYXin
 * @Date: 2022-10-14 22:04:41
 * @LastEditTime: 2023-09-21 09:15:15
 * @FilePath: \cpp1c:\c\3\Cjosephus.c
 */
#include <stdio.h>

int main()
{
    int n, k, x = 0, arr[100], j = 0, a;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        arr[i] = 1;
    }
    int i = 1;
    a = n;
    while (a > 1)
    {
        for (i = 1; i <= n; i++)
        {
            if (arr[i] == 1 && x != k)
            {
                x++;
            }
            while (x == k)
            {
                arr[i] = 0;
                a--;
                x = 0;
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            printf("%d", i);
        }
    }
    return 0;
}
