#include <stdio.h>
#include <string.h>

int main()
{
    int n, a, b, y = 0, u = 0, o = 0;
    char str[1001], str2[1001];
    scanf("%d", &n);
    scanf("%s", str);
    a = strlen(str);
    b = a;
    strncpy(str2, str, b);
    for (; n > 0; n--)
    {
        for (int i = 0; i <= b - 1; i++)
        {
            int q = 0, w = 0;
            if (b >= 7)
            {
                if (i == 0)
                {
                    for (int j = 1; j <= 3; j++)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                }
                else if (i == 1)
                {

                    for (int j = 2; j <= 4; j++)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                    for (int j = 0; j == 0; j--)
                    {
                        if (str[0] == 'A')
                            q++;
                        else if (str[0] == 'B')
                            w++;
                    }
                }
                else if (i == 2)
                {

                    for (int j = 3; j <= 5; j++)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                    for (int j = 0; j <= 1; j++)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                }
                else if (i > 2 && i < b - 3)
                {
                    for (int j = i + 1; j <= i + 3; j++)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                    for (int j = i - 1; j >= i - 3; j--)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                }
                else if (i == b - 1)
                {
                    for (int j = b - 2; j >= b - 4; j--)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                }
                else if (i == b - 2)
                {
                    for (int j = 0; j >= 0; j--)
                    {
                        if (str[b - 1] == 'A')
                            q++;
                        else if (str[b - 1] == 'B')
                            w++;
                    }
                    for (int j = b - 3; j >= b - 5; j--)
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                }
                else if (i == b - 3)
                {
                    for (int j = b - 4; j >= b - 6; j--)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                    for (int j = b - 1; j >= b - 2; j--)
                    {
                        if (str[j] == 'A')
                            q++;
                        else if (str[j] == 'B')
                            w++;
                    }
                }
            }
            else if (b < 7)
            {
                if (b == 6)
                {
                    if (i == 0)
                    {
                        for (int j = 1; j <= 3; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 1)
                    {
                        for (int j = 2; j <= 4; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j == 0; j--)
                        {
                            if (str[0] == 'A')
                                q++;
                            else if (str[0] == 'B')
                                w++;
                        }
                    }
                    else if (i == 2)
                    {
                        for (int j = 3; j <= 5; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j <= 1; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 5)
                    {
                        for (int j = 4; j >= 2; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 4)
                    {
                        for (int j = 0; j >= 0; j--)
                        {
                            if (str[5] == 'A')
                                q++;
                            else if (str[5] == 'B')
                                w++;
                        }
                        for (int j = 3; j >= 1; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 3)
                    {
                        for (int j = 2; j >= 0; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 5; j >= 4; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                }
                if (b = 5)
                {
                    if (i == 0)
                    {
                        for (int j = 1; j <= 3; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 1)
                    {

                        for (int j = 2; j <= 4; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j == 0; j--)
                        {
                            if (str[0] == 'A')
                                q++;
                            else if (str[0] == 'B')
                                w++;
                        }
                    }
                    else if (i == 2)
                    {

                        for (int j = 3; j <= 4; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j <= 1; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 4)
                    {
                        for (int j = 3; j >= 1; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 3)
                    {
                        for (int j = 2; j >= 0; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 4; j >= 4; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                }
                if (b == 4)
                {
                    if (i == 0)
                    {
                        for (int j = 1; j <= 3; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 1)
                    {

                        for (int j = 2; j <= 3; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j == 0; j--)
                        {
                            if (str[0] == 'A')
                                q++;
                            else if (str[0] == 'B')
                                w++;
                        }
                    }
                    else if (i == 2)
                    {

                        for (int j = 3; j <= 3; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j <= 1; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 3)
                    {
                        for (int j = 2; j >= 0; j--)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                }
                if (b == 3)
                {
                    if (i == 0)
                    {
                        for (int j = 1; j <= 2; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 1)
                    {

                        for (int j = 2; j <= 2; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                        for (int j = 0; j == 0; j--)
                        {
                            if (str[0] == 'A')
                                q++;
                            else if (str[0] == 'B')
                                w++;
                        }
                    }
                    else if (i == 2)
                    {
                        for (int j = 0; j <= 1; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                }
                if (b == 2)
                {
                    if (i == 0)
                    {
                        for (int j = 1; j <= 1; j++)
                        {
                            if (str[j] == 'A')
                                q++;
                            else if (str[j] == 'B')
                                w++;
                        }
                    }
                    else if (i == 1)
                    {
                        for (int j = 0; j == 0; j--)
                        {
                            if (str[0] == 'A')
                                q++;
                            else if (str[0] == 'B')
                                w++;
                        }
                    }
                }
                if (b == 1)
                {
                    q = o;
                    w = 0;
                }
            }
            y = (int)str[i] == 65;
            u = (int)str[i] == 66;
            o = (int)str[i] == 46;
            if (y == 1 && w >= 1)
                str2[i] = '.';
            else if (u == 1 && q >= 1)
                str2[i] = '.';
            else
            {
                if (y == 1 && q <= 1)
                    str2[i] = '.';
                else if (u == 1 && w <= 1)
                    str2[i] = '.';
                else if (o == 1)
                {
                    if (q >= 2 && q <= 4)
                    {
                        if (w == 0)
                            str2[i] = 'A';
                    }
                    if (w >= 2 && w <= 4)
                    {
                        if (q == 0)
                            str2[i] = 'B';
                    }
                }
                else if (y == 1 && q >= 5)
                    str2[i] = '.';
                else if (u == 1 && w >= 5)
                    str2[i] = '.';
            }
        }
        strncpy(str, str2, b);
    }
    for (int i = 0; i <= b - 1; i++)
    {
        putchar(str[i]);
    }
    return 0;
}