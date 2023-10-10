#include <stdio.h>

int X(int a, int arr[100])
{
    int ar[10] = {1};
    for (int i = 10 * (a - 1) + 1; i <= 10 * (a - 1) + 9; i++)
    {

        if (ar[arr[i]] == 1)
            ar[arr[i]]--;
        if (ar[i] < 1)
            return 0;
    }
    return 1;
}
/*if (b == 1)
    {
        for (int i = a; i <= 80 + a; i += 10)
        {
            if (ar[i] == 1)
                ar[i]--;
            if (ar[i] < 1)
                return 0;
        }
        return 1;
    }*/
int main()
{
    int arr[100], i = 1, c = 0;
    for (int j = 1; j <= 9; j++)
    {
        do
        {
            scanf("%d", &arr[i]);
            i++;
        } while ((i % 10) != 0);
        i = i + 1;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (X(i, 0) == 1)
            c++;
        if (X(i, 0) == 0)
        {
            break;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (X(i, arr[100]) == 1)
            c++;
        if (X(i, arr[100]) == 0)
        {
            break;
        }
    }
    if (c == 18)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}