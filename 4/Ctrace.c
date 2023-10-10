#include <stdio.h>

int main()
{
    int m, n, x, y, count = 0;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    char arr[100][100];
    int vis[100][100];
    for (int x = 1; x <= m; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            arr[x][y] = getchar();
            vis[x][y] = 1;
            if ((int)arr[x][y] == 35)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    count--;
    printf("%d %d\n", x, y);
    while (count > 0)
    {
        vis[x][y] = 0;
        if (x == 1 && y == 1)
        {
            if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            else if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (x == m && y == n)
        {
            if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (x == 1 && y == n)
        {
            if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            else if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (x == m && y == 1)
        {
            if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (x == 1 && (y != 1 && y != n))
        {
            if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            else if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            else if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (x == m && (y != 1 && y != n))
        {
            if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            else if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (y == 1 && (x != 1 && x != m))
        {
            if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            else if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else if (y == n && (x != 1 && x != m))
        {
            if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            else if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
        else
        {
            if ((int)arr[x + 1][y] == 35 && (vis[x + 1][y] == 1))
            {
                x++;
            }
            else if ((int)arr[x][y - 1] == 35 && (vis[x][y - 1] == 1))
            {
                y--;
            }
            else if ((int)arr[x][y + 1] == 35 && (vis[x][y + 1] == 1))
            {
                y++;
            }
            else if ((int)arr[x - 1][y] == 35 && (vis[x - 1][y] == 1))
            {
                x--;
            }
            count--;
            printf("%d %d\n", x, y);
            vis[x][y] = 0;
        }
    }
    return 0;
}