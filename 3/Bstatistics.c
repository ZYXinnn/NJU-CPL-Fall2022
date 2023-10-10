#include <stdio.h>

int main()
{
    char a;
    int arr[1000] = {0}, arr1[1000] = {0};
    int b, c = 0, d = 0, e = 0, max = 1;
    scanf("%d", &b);
    int i = 1;
    while (i <= b + 1)
    {
        scanf("%c", &a);
        arr[(int)a]++;
        arr1[(int)a]++;
        i++;
    }
    for (int i = 65; i <= 122; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    while (max >= 1)
    {
        for (int i = 97, j = 65; i <= 122 && j <= 90; i++, j++)
        {
            if (arr[i] > 0 && arr[j] > 0)
            {
                if (arr[i] == max)
                {
                    printf("=");
                    arr[i]--;
                }
                else
                    printf(" ");
                if (arr[j] == max)
                {
                    printf("=");
                    arr[j]--;
                }
                else
                    printf(" ");
                printf(" ");
            }
            else if (arr[i] > 0 && arr[j] == 0)
            {
                if (arr[i] == max)
                {
                    printf("=");
                    arr[i]--;
                }
                else
                    printf(" ");
                printf(" ");
            }
            else if (arr[j] > 0 && arr[i] == 0)
            {
                if (arr[j] == max)
                {
                    printf("=");
                    arr[j]--;
                }
                else
                    printf(" ");
                printf(" ");
            }
        }
        printf("\n");
        max--;
    }
    for (int i = 65; i <= 90; i++)
    {
        if (arr1[i] > 0)
            c++;
    }
    for (int i = 97; i <= 122; i++)
    {
        if (arr1[i] > 0)
            d++;
    }
    for (int i = 65; i <= 90; i++)
    {
        if (arr1[i] > 0 && arr1[i + 32] > 0)
            e++;
    }
    for (int i = 1; i <= (2 * c + 2 * d - e - 1); i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 97, j = 65; i <= 122 && j <= 90; i++, j++)
    {
        if (arr1[i] > 0 && arr1[j] > 0)
            printf("%c%c ", (char)i, (char)j);
        else if (arr1[i] > 0)
            printf("%c ", (char)i);
        else if (arr1[j] > 0)
            printf("%c ", (char)j);
    }
    return 0;
}